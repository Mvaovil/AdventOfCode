#include <iostream>
#include <queue>
#include <unordered_set>
#include <climits>
using namespace std;

struct Nodo {
    int x, y, coste, contador_a, contador_b;
    Nodo(int x, int y, int coste, int contador_a, int contador_b)
        : x(x), y(y), coste(coste), contador_a(contador_a), contador_b(contador_b) {}
};

int obtenerCosteMinimo(int objetivoX, int objetivoY, const int moverA_X, const int moverA_Y, int costeA, const int moverB_X, const int moverB_Y, int costeB) {
    queue<Nodo> q;
    unordered_set<string> visitados;

    q.push(Nodo(0, 0, 0, 0, 0));
    visitados.insert("0,0");

    while (!q.empty()) {
        Nodo actual = q.front();
        q.pop();

        if (actual.x == objetivoX && actual.y == objetivoY) {
            return actual.coste;
        }

        if (actual.contador_a < 100) {
            int nuevoX = actual.x + moverA_X;
            int nuevoY = actual.y + moverA_Y;
            if (visitados.find(to_string(nuevoX) + "," + to_string(nuevoY)) == visitados.end()) {
                q.push(Nodo(nuevoX, nuevoY, actual.coste + costeA, actual.contador_a + 1, actual.contador_b));
                visitados.insert(to_string(nuevoX) + "," + to_string(nuevoY));
            }
        }

        if (actual.contador_b < 100) {
            int nuevoX = actual.x + moverB_X;
            int nuevoY = actual.y + moverB_Y;
            if (visitados.find(to_string(nuevoX) + "," + to_string(nuevoY)) == visitados.end()) {
                q.push(Nodo(nuevoX, nuevoY, actual.coste + costeB, actual.contador_a, actual.contador_b + 1));
                visitados.insert(to_string(nuevoX) + "," + to_string(nuevoY));
            }
        }
    }

    return INT_MAX;
}

int main() {
    int moverA_X = 94, moverA_Y = 34, costeA = 3;
    int moverB_X = 22, moverB_Y = 67, costeB = 1;
    int objetivoX = 8400, objetivoY = 5400;

    int costeMinimo = obtenerCosteMinimo(objetivoX, objetivoY, moverA_X, moverA_Y, costeA, moverB_X, moverB_Y, costeB);

    if (costeMinimo == INT_MAX) {
        cout << "No es posible ganar el premio." << endl;
    } else {
        cout << "El número mínimo de tokens para poder ganar el premio es: " << costeMinimo << endl;
    }

    return 0;
}

