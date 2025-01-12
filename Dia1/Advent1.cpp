#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

// Función recursiva para calcular la distancia entre las dos listas
int calcularDistancia(const vector<int>& lista1, const vector<int>& lista2, int inicio, int fin) {
    // El caso base es que si el rango tiene un solo elemento, se calcula la diferencia entre los elementos correspondientes
    if (inicio == fin) {
        return abs(lista1[inicio] - lista2[inicio]);
    }
    
    // Caso recursivo, que debemos dividir la lista básicamente
    int mitad = (inicio + fin) / 2;
    int distanciaIzquierda = calcularDistancia(lista1, lista2, inicio, mitad);
    int distanciaDerecha = calcularDistancia(lista1, lista2, mitad + 1, fin);
    
    // Combinar los resultados de las sublistas
    return distanciaIzquierda + distanciaDerecha;
}

// Ahora ordenamos las listas y llamamos a la función recursiva para calcular la distancia
int divideYVenceras(vector<int>& lista1, vector<int>& lista2) {
    // Ordenar las listas antes de calcular las distancias
    sort(lista1.begin(), lista1.end());
    sort(lista2.begin(), lista2.end());

    // Llamar a la función recursiva para calcular la distancia entre las listas
    return calcularDistancia(lista1, lista2, 0, lista1.size() - 1);
}

int main() {
    // Abrir el archivo input.txt
    ifstream archivo("input.txt");
    string linea;
    
    vector<int> lista1;
    vector<int> lista2;
    
    // Leer las líneas del archivo
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        int num;
        
        // Leer cada número en la línea y agregarlo a las listas
        while (ss >> num) {
            if (lista1.size() < lista2.size()) {
                lista1.push_back(num);
            } else {
                lista2.push_back(num);
            }
        }
    }
    
    // Asegurarnos de que ambas listas tengan el mismo tamaño
    if (lista1.size() != lista2.size()) {
        cout << "Las listas no tienen el mismo tamaño." << endl;
        return 1;
    }
    
    // Llamar a la función divideYVenceras para obtener el resultado
    int resultado = divideYVenceras(lista1, lista2);
    
    // Imprimir el resultado (debería ser 11 si las listas son las mismas como en el ejemplo anterior)
    cout << "La distancia total es: " << resultado << endl;
    
    return 0;
}
