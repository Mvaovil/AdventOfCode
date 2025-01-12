#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

// Función para leer los datos desde un archivo y almacenarlos en un vector
void cargarDatos(vector<long long> &datos) {
    ifstream archivo("input11.txt");
    string linea;

    if (getline(archivo, linea)) {
        stringstream ss(linea);
        long long numero;
        while (ss >> numero) {
            datos.push_back(numero);
        }
    }
    archivo.close();
}

// Función recursiva con memorización para calcular predicciones basadas en blinks
int calcularPredicciones(long long valor, int blinksRestantes, unordered_map<string, int> &cache) {
    if (blinksRestantes == 0) return 1; // Caso base: sin blinks restantes

    // Generar una clave única para el estado actual
    string clave = to_string(valor) + ":" + to_string(blinksRestantes);

    // Si ya hemos calculado este estado, devolver el resultado memorizado
    if (cache.find(clave) != cache.end()) return cache[clave];

    int resultado = 0;

    if (valor == 0) {
        // Si el valor es 0, cambia a 1 y reduce un blink
        resultado = calcularPredicciones(1, blinksRestantes - 1, cache);
    } else {
        string valorStr = to_string(valor);
        if (valorStr.size() % 2 == 0) {
            // Si el número tiene una longitud par, dividir en dos mitades y calcular recursivamente
            int mitad1 = stoi(valorStr.substr(0, valorStr.size() / 2));
            int mitad2 = stoi(valorStr.substr(valorStr.size() / 2));
            resultado = calcularPredicciones(mitad1, blinksRestantes - 1, cache) +
                        calcularPredicciones(mitad2, blinksRestantes - 1, cache);
        } else {
            // Si el número tiene longitud impar, multiplicar por 2024 y continuar
            resultado = calcularPredicciones(valor * 2024, blinksRestantes - 1, cache);
        }
    }

    // Guardar el resultado en la caché
    cache[clave] = resultado;
    return resultado;
}

int main() {
    vector<long long> valoresIniciales; // Vector para almacenar los valores de entrada
    cargarDatos(valoresIniciales);      // Cargar los datos desde el archivo

    int cantidadValores = valoresIniciales.size();
    int cantidadBlinks = 25;            // Número de blinks permitidos
    unordered_map<string, int> cache;  // Caché para memorización

    int totalPiedras = 0;

    // Procesar cada valor inicial
    for (int i = 0; i < cantidadValores; i++) {
        totalPiedras += calcularPredicciones(valoresIniciales[i], cantidadBlinks, cache);
    }

    // Mostrar el resultado final
    cout << "Total de piedras tras " << cantidadBlinks << " blinks: " << totalPiedras << endl;

    return 0;
}

