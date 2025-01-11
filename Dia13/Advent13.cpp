#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

int calcCosteMinimo(int moverA_X, int moverA_Y, int costeA, int moverB_X, int moverB_Y, int costeB, int objetivoX, int objetivoY) {
    const int LIMITE = 100;
    int costeMinimo = INT_MAX;

    for (int a = 0; a <= LIMITE; ++a) {
        for (int b = 0; b <= LIMITE; ++b) {
            int x = a * moverA_X + b * moverB_X;
            int y = a * moverA_Y + b * moverB_Y;

            if (x == objetivoX && y == objetivoY) {
                int coste = a * costeA + b * costeB;
                costeMinimo = min(costeMinimo, coste);
            }
        }
    }

    return (costeMinimo == INT_MAX) ? -1 : costeMinimo;
}

int main() {
    vector<tuple<int, int, int, int, int, int, int, int>> maquinas = {
        {94, 34, 3, 22, 67, 1, 8400, 5400},
        {26, 66, 3, 67, 21, 1, 12748, 12176},
        {17, 86, 3, 84, 37, 1, 7870, 6450},
        {69, 23, 3, 27, 71, 1, 18641, 10279}
    };

    int tokensTotales = 5000;

    vector<int> costesMinimos;
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

    vector<int> dp(tokensTotales + 1, -1);
    dp[0] = 0;

    for (int coste : costesMinimos) {
        for (int j = tokensTotales; j >= coste; --j) {
            if (dp[j - coste] != -1) {
                dp[j] = max(dp[j], dp[j - coste] + 1);
            }
        }
    }

    int maxPremios = 0;
    int costeMinimoTotal = INT_MAX;
    for (int j = 0; j <= tokensTotales; ++j) {
        if (dp[j] > maxPremios) {
            maxPremios = dp[j];
            costeMinimoTotal = j;
        } else if (dp[j] == maxPremios && j < costeMinimoTotal) {
            costeMinimoTotal = j;
        }
    }

    if (maxPremios == 0) {
        cout << "No es posible ganar ningún premio." << endl;
    } else {
        cout << "Número máximo de premios posibles: " << maxPremios << endl;
        cout << "Coste mínimo total para ganar esos premios: " << costeMinimoTotal << " tokens." << endl;
    }

    return 0;
}

