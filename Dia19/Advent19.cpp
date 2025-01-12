#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// Función recursiva con memoización para verificar si un diseño se puede formar o no
bool formar(const string& diseño, const vector<string>& patrones, unordered_map<string, bool>& memo) {
    if (diseño.empty()) return true;  // Caso base de la recursion, si el diseño está vacío, se puede formar

    if (memo.find(diseño) != memo.end()) return memo[diseño];  // Si ya hemos calculado este diseño devolvemos el resultado y ya

    // Intentar formar el diseño usando cada patrón
    for (const string& patron : patrones) {
        if (diseño.find(patron) == 0) {  // Verifica si el diseño comienza con el patrón (Importante igualarlo a 0...)
            // Si el resto del diseño se puede formar, devolver true
            if (formar(diseño.substr(patron.size()), patrones, memo)) {
                return memo[diseño] = true; //Memorizar el resultado como verdadero
            }
        }
    }

    // Si no se puede formar el diseño, guardar el resultado en la tabla hash y devolver false
    return memo[diseño] = false;
}

int main() {
    // Patrones disponibles para formar los diseños
    vector<string> patrones = {"r", "wr", "b", "g", "bwu", "rb", "gb", "br"};
    // Diseños que se van a evaluar (Dados por el problema)
    vector<string> diseños = {
        "brwrr", "bggr", "gbbr", "rrbgbr", "ubwu", "bwurrg", "brgr", "bbrgwb"
    };

    unordered_map<string, bool> memo;  // Mapa para guardar los resultados de subproblemas

    int cantidadDiseños = 0;

    // Evaluar cada diseño
    for (const string& diseño : diseños) {
        if (formar(diseño, patrones, memo)) {  //SOLO si el diseño se puede formar, incrementar el contador 
            cantidadDiseños++;
        }
    }

    // Mostrar el número de diseños que se pueden formar (Debería devolver 6)
    cout << "Número de diseños posibles: " << cantidadDiseños << endl;

    return 0;
}
