#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

// Definición de la estructura Nodo, que representa un nodo del árbol de operaciones
struct Nodo {
    int valor;      
    char operador; 
    Nodo* izquierdo;  // Apuntador al subárbol izquierdo
    Nodo* derecho;    // Apuntador al subárbol derecho

    // Constructor para los nodos con un valor (números)
    Nodo(int v) : valor(v), operador(0), izquierdo(nullptr), derecho(nullptr) {}

    // Constructor para los nodos con un operador y dos subárboles
    Nodo(char op, Nodo* izq, Nodo* der) : valor(0), operador(op), izquierdo(izq), derecho(der) {}
};

// Función recursiva que evalúa el valor de un árbol de operaciones
int arbol(Nodo* nodo) {
    if (!nodo->operador) return nodo->valor;  // Si no hay operador, es un número, devolver su valor

    // Si hay un operador, evaluamos los subárboles izquierdo y derecho
    int izq = arbol(nodo->izquierdo);
    int der = arbol(nodo->derecho);

    // Aplicar el operador
    if (nodo->operador == '+') return izq + der;
    if (nodo->operador == '*') return izq * der;

    throw invalid_argument("Operador inválido");  // Si el operador es inválido
}

// Función recursiva para crear todos los árboles posibles a partir de una lista de números
vector<Nodo*> crearArbol(const vector<int>& numeros, int inicio, int fin) {
    if (inicio == fin) return {new Nodo(numeros[inicio])};  // Caso base, solo hay un número

    vector<Nodo*> resultados;  

    // Recorremos todas las posiciones posibles para dividir la lista en dos sublistas usando un bucle for con un valor i 
    for (int i = inicio; i < fin; ++i) {
        // Crear todos los árboles para el subárbol izquierdo y derecho
        vector<Nodo*> izquierdo = crearArbol(numeros, inicio, i);
        vector<Nodo*> derecho = crearArbol(numeros, i + 1, fin);

        // Crear un árbol con un operador (+ o *) entre cada par de subárboles
        for (Nodo* izq : izquierdo) {
            for (Nodo* der : derecho) {
                resultados.push_back(new Nodo('+', izq, der));  
                resultados.push_back(new Nodo('*', izq, der));  
            }
        }
    }

    return resultados;  // Devolver todos los árboles generados
}

// Función que verifica si existe un árbol que evalúa a un valor objetivo
bool ecval(int objetivo, const vector<int>& numeros) {
    vector<Nodo*> arboles = crearArbol(numeros, 0, numeros.size() - 1);  // Crear todos los árboles posibles

    // Evaluar cada árbol
    for (Nodo* nodo : arboles) {
        if (arbol(nodo) == objetivo) return true;  // Si encontramos un árbol que da el resultado objetivo
    }

    return false;  // Si no se encuentra ningún árbol que dé el resultado objetivo
}

int main() {
    // Lista de ecuaciones con sus resultados objetivo
    vector<pair<int, vector<int>>> ecuaciones = {
        {190, {10, 19}},
        {3267, {81, 40, 27}},
        {83, {17, 5}},
        {156, {15, 6}},
        {7290, {6, 8, 6, 15}},
        {161011, {16, 10, 13}},
        {192, {17, 8, 14}},
        {21037, {9, 7, 18, 13}},
        {292, {11, 6, 16, 20}}
    };

    int resultadoTotal = 0;  // Variable para almacenar la suma de los objetivos alcanzados

    // Recorrer todas las ecuaciones y verificar si podemos obtener el resultado objetivo
    for (const auto& ecuacion : ecuaciones) {
        int objetivo = ecuacion.first;  // Objetivo de la ecuación
        const vector<int>& numeros = ecuacion.second;  // Lista de números

        if (ecval(objetivo, numeros)) {
            resultadoTotal += objetivo;  // Si es posible, sumamos el objetivo
        }
    }

    // Imprimir el resultado total de calibración
    cout << "Resultado total de calibración: " << resultadoTotal << endl;

    return 0;
}
