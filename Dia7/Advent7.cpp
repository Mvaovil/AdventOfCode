#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

// Función para cargar el archivo y extraer objetivos y listas de números
void cargarDatos(vector<long long> &objetivos, vector<vector<int>> &listasNumeros) {
    ifstream archivo("input7.txt");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string numero;

        // Extraer el objetivo y los números de la línea
        if (getline(ss, numero, ':')) {
            objetivos.push_back(stoll(numero));

            while (ss.peek() == ' ')
                ss.get();

            vector<int> numerosTemp;
            while (getline(ss, numero, ' ')) {
                if (!numero.empty()) {
                    numerosTemp.push_back(stoll(numero));
                }
            }

            listasNumeros.push_back(numerosTemp);
        }
    }
    archivo.close();
}

// Función para construir un árbol de operaciones y verificar si se alcanza el objetivo
bool verificarConArbol(long long objetivo, const vector<int> &numeros, int indice, long long valorActual) {
    if (indice == numeros.size()) {
        return valorActual == objetivo;
    }

    // Sumar el siguiente número
    if (verificarConArbol(objetivo, numeros, indice + 1, valorActual + numeros[indice])) {
        return true;
    }

    // Multiplicar el siguiente número
    if (verificarConArbol(objetivo, numeros, indice + 1, valorActual * numeros[indice])) {
        return true;
    }

    return false;
}

// Función para procesar los datos y calcular el total
long long calcularSumaObjetivos(const vector<long long> &objetivos, const vector<vector<int>> &listasNumeros) {
    long long sumaTotal = 0;
    for (size_t i = 0; i < objetivos.size(); ++i) {
        if (verificarConArbol(objetivos[i], listasNumeros[i], 1, listasNumeros[i][0])) {
            sumaTotal += objetivos[i];
        }
    }
    return sumaTotal;
}

int main() {
    vector<long long> objetivos;
    vector<vector<int>> listasNumeros;
    cargarDatos(objetivos, listasNumeros);

    long long resultado = calcularSumaObjetivos(objetivos, listasNumeros);

    cout << "Resultado total de calibración: " << resultado << endl;

    return 0;
}

