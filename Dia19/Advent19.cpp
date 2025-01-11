#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

bool formar(const string& diseño, const vector<string>& patrones, unordered_map<string, bool>& memo) {
    if (diseño.empty()) return true;

    if (memo.find(diseño) != memo.end()) return memo[diseño];

    for (const string& patron : patrones) {
        if (diseño.find(patron) == 0) {
            if (formar(diseño.substr(patron.size()), patrones, memo)) {
                return memo[diseño] = true;
            }
        }
    }

    return memo[diseño] = false;
}

int main() {
    vector<string> patrones = {"r", "wr", "b", "g", "bwu", "rb", "gb", "br"};
    vector<string> diseños = {
        "brwrr",
        "bggr",
        "gbbr",
        "rrbgbr",
        "ubwu",
        "bwurrg",
        "brgr",
        "bbrgwb"
    };

    unordered_map<string, bool> memo;

    int cantidadDiseños = 0;

    for (const string& diseño : diseños) {
        if (formar(diseño, patrones, memo)) {
            cantidadDiseños++;
        }
    }

    cout << "Número de diseños posibles: " << cantidadDiseños << endl;

    return 0;
}

