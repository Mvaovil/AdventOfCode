#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <string>
#include <sstream>
using namespace std;

struct Nodo {
    int valor;
    char operador;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int v) : valor(v), operador(0), izquierdo(nullptr), derecho(nullptr) {}
    Nodo(char op, Nodo* izq, Nodo* der) : valor(0), operador(op), izquierdo(izq), derecho(der) {}
};

int arbol(Nodo* nodo) {
    if (!nodo->operador) return nodo->valor;

    int izq = arbol(nodo->izquierdo);
    int der = arbol(nodo->derecho);

    if (nodo->operador == '+') return izq + der;
    if (nodo->operador == '*') return izq * der;

    throw invalid_argument("Operador inválido");
}

vector<Nodo*> crearArbol(const vector<int>& numeros, int inicio, int fin) {
    if (inicio == fin) return {new Nodo(numeros[inicio])};

    vector<Nodo*> resultados;

    for (int i = inicio; i < fin; ++i) {
        vector<Nodo*> izquierdo = crearArbol(numeros, inicio, i);
        vector<Nodo*> derecho = crearArbol(numeros, i + 1, fin);

        for (Nodo* izq : izquierdo) {
            for (Nodo* der : derecho) {
                resultados.push_back(new Nodo('+', izq, der));
                resultados.push_back(new Nodo('*', izq, der));
            }
        }
    }

    return resultados;
}

bool ecval(int objetivo, const vector<int>& numeros) {
    vector<Nodo*> arboles = crearArbol(numeros, 0, numeros.size() - 1);

    for (Nodo* nodo : arboles) {
        if (arbol(nodo) == objetivo) return true;
    }

    return false;
}

int main() {
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

    int resultadoTotal = 0;

    for (const auto& ecuacion : ecuaciones) {
        int objetivo = ecuacion.first;
        const vector<int>& numeros = ecuacion.second;

        if (ecval(objetivo, numeros)) {
            resultadoTotal += objetivo;
        }
    }

    cout << "Resultado total de calibración: " << resultadoTotal << endl;

    return 0;
}

