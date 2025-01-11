#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int calcularDistancia(const vector<int>& lista1, const vector<int>& lista2, int inicio, int fin) {
    if (inicio == fin) {
        return abs(lista1[inicio] - lista2[inicio]);
    }
    
    int mitad = (inicio + fin) / 2;
    int distanciaIzquierda = calcularDistancia(lista1, lista2, inicio, mitad);
    int distanciaDerecha = calcularDistancia(lista1, lista2, mitad + 1, fin);
    
    return distanciaIzquierda + distanciaDerecha;
}

int divideYVenceras(vector<int>& lista1, vector<int>& lista2) {
    sort(lista1.begin(), lista1.end());
    sort(lista2.begin(), lista2.end());
    return calcularDistancia(lista1, lista2, 0, lista1.size() - 1);
}

int main() {
    vector<int> lista1 = {3, 4, 2, 1, 3, 3};
    vector<int> lista2 = {4, 3, 5, 3, 9, 3};
    
    int resultado = divideYVenceras(lista1, lista2);
    
    cout << "La distancia total es: " << resultado << endl;
    
    return 0;
}

