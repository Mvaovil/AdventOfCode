#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

// Calcula el coste mínimo para alcanzar el objetivo usando combinaciones de movimientos
int calcCosteMinimo(int moverA_X, int moverA_Y, int costeA, int moverB_X, int moverB_Y, int costeB, int objetivoX, int objetivoY) {
    const int LIMITE = 100;  // Límite de movimientos
    int costeMinimo = INT_MAX;  // Inicializa el coste como infinito

    // Recorre todas las combinaciones posibles de movimientos
    for (int a = 0; a <= LIMITE; ++a) {
        for (int b = 0; b <= LIMITE; ++b) {
            int x = a * moverA_X + b * moverB_X;
            int y = a * moverA_Y + b * moverB_Y;

            // Si coincide con el objetivo, calcula el coste
            if (x == objetivoX && y == objetivoY) {
                int coste = a * costeA + b * costeB;
                costeMinimo = min(costeMinimo, coste);
            }
        }
    }

    // Retorna el coste mínimo encontrado, o -1 si no se encontró
    return (costeMinimo == INT_MAX) ? -1 : costeMinimo;
}

int main() {
    // Datos de las máquinas
    vector<tuple<int, int, int, int, int, int, int, int>> maquinas = {
        {94, 34, 3, 22, 67, 1, 8400, 5400},
        {26, 66, 3, 67, 21, 1, 12748, 12176},
        {17, 86, 3, 84, 37, 1, 7870, 6450},
        {69, 23, 3, 27, 71, 1, 18641, 10279}
    };

    int tokensTotales = 5000;  // Tokens disponibles
    vector<int> costesMinimos;

    // Calcula el coste mínimo para cada máquina
    for (const auto& maquina : maquinas) {
        int moverA_X, moverA_Y, costeA, moverB_X, moverB_Y, costeB, objetivoX, objetivoY;
        tie(moverA_X, moverA_Y, costeA, moverB_X, moverB_Y, costeB, objetivoX, objetivoY) = maquina;

        int costeMinimo = calcCosteMinimo(moverA_X, moverA_Y, costeA, moverB_X, moverB_Y, costeB, objetivoX, objetivoY);
        if (costeMinimo != -1) {
            costesMinimos.push_back(costeMinimo);
        }
    }

    if (costesMinimos.empty()) {
        cout << "No hay ninguna máquina en la que sea posible ganar un premio." << endl;
        return 0;
    }

    // Inicializa la DP
    vector<int> dp(tokensTotales + 1, -1);
    dp[0] = 0;

    // Aplica programación dinámica para encontrar el número máximo de premios
    for (int coste : costesMinimos) {
        for (int j = tokensTotales; j >= coste; --j) {
            if (dp[j - coste] != -1) {
                dp[j] = max(dp[j], dp[j - coste] + 1);
            }
        }
    }

    int maxPremios = 0, costeMinimoTotal = INT_MAX;

    // Encuentra el máximo número de premios y su coste mínimo
    for (int j = 0; j <= tokensTotales; ++j) {
        if (dp[j] > maxPremios) {
            maxPremios = dp[j];
            costeMinimoTotal = j;
        } else if (dp[j] == maxPremios && j < costeMinimoTotal) {
            costeMinimoTotal = j;
        }
    }

    // Muestra el resultado
    if (maxPremios == 0) {
        cout << "No es posible ganar ningún premio." << endl;
    } else {
        cout << "Número máximo de premios posibles: " << maxPremios << endl;
        cout << "Coste mínimo total para ganar esos premios: " << costeMinimoTotal << " tokens." << endl;
    }

    return 0;
}
