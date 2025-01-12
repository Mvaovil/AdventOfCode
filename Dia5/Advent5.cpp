#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

// Función para verificar si una actualización es válida según las reglas del grafo
bool actVal(const vector<int>& actualizacion, const map<int, vector<int>>& grafo) {
    // Crear un mapa que almacena el índice de cada página en la actualización
    map<int, int> indice;
    for (int i = 0; i < actualizacion.size(); ++i) {
        indice[actualizacion[i]] = i;
    }

    // Verificar todas las dependencias del grafo
    for (const auto& entrada : grafo) {
        int pagina = entrada.first;
        const vector<int>& vecinos = entrada.second;

        for (int vecino : vecinos) {
            // Si ambas páginas están en la actualización, comprobar el orden
            if (indice.count(pagina) && indice.count(vecino) && indice[pagina] >= indice[vecino]) {
                return false; // No se cumple la dependencia
            }
        }
    }
    return true; // Todas las dependencias son válidas
}

int main() {
    // Abrir el archivo de entrada
    ifstream archivo("input.txt");
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo 'input.txt'" << endl;
        return 1;
    }

    string linea;
    map<int, vector<int>> grafo;  // Grafo que representa las relaciones de dependencia
    vector<vector<int>> actualizaciones;  // Lista de actualizaciones leídas del archivo

    // Leer el archivo línea por línea
    while (getline(archivo, linea)) {
        if (linea.empty()) continue; // Ignorar líneas vacías

        if (linea.find("|") != string::npos) {
            // Si la línea contiene una relación (X|Y), añadirla al grafo
            stringstream ss(linea);
            int x, y;
            ss >> x;
            ss.ignore(); // Ignorar el carácter '|'
            ss >> y;
            grafo[x].push_back(y); // Añadir la relación al grafo
        } else {
            // Si no contiene una relación, procesar como una actualización
            stringstream ss(linea);
            vector<int> actualizacion;
            int numero;
            while (ss >> numero) {
                actualizacion.push_back(numero); // Añadir página a la actualización
                if (ss.peek() == ',') ss.ignore(); // Ignorar comas
            }
            actualizaciones.push_back(actualizacion); // Guardar la actualización
        }
    }

    archivo.close(); // Cerrar el archivo después de leerlo

    int suma = 0; // Inicializar la suma de las páginas centrales de actualizaciones válidas

    // Procesar cada actualización
    for (const auto& actualizacion : actualizaciones) {
        if (actVal(actualizacion, grafo)) {
            // Si la actualización es válida, sumar el valor de su página central
            int centro = actualizacion[actualizacion.size() / 2];
            suma += centro;
        }
    }

    cout << "Suma de páginas centrales: " << suma << endl;

    return 0;
}
