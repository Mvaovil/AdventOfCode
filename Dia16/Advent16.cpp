#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;

class Nodo {
public:
    int x, y;          // Coordenadas del nodo
    int dirX, dirY;    // Dirección actual del movimiento
    int acumulado;     // Costo acumulado hasta este nodo

    // Constructor para inicializar el nodo
    Nodo(int posX = 0, int posY = 0, int deltaX = 0, int deltaY = 0, int cost = 0)
        : x(posX), y(posY), dirX(deltaX), dirY(deltaY), acumulado(cost) {}

    // Sobrecarga del operador '>' para prioridad en la cola
    bool operator>(const Nodo& otro) const {
        return acumulado > otro.acumulado;
    }

    // Verifica si la posición actual es válida en el laberinto
    bool es_valido(const vector<vector<char>>& laberinto) const {
        int filas = laberinto.size();
        int columnas = laberinto[0].size();
        return x >= 0 && x < filas && y >= 0 && y < columnas && laberinto[x][y] != '#';
    }

    // Genera un nuevo nodo avanzando en la dirección actual
    Nodo avanzar() const {
        return Nodo(x - dirX, y + dirY, dirX, dirY, acumulado);
    }

    // Genera un nuevo nodo rotando la dirección actual
    Nodo girar(bool sentido_horario) const {
        if (sentido_horario) {
            return Nodo(x, y, dirY, -dirX, acumulado);
        } else {
            return Nodo(x, y, -dirY, dirX, acumulado);
        }
    }
};

// Función para encontrar la ruta más corta en el laberinto usando un árbol implícito
vector<vector<int>> encontrarRuta(const vector<vector<char>>& laberinto, Nodo inicio, Nodo destino) {
    int filas = laberinto.size();
    int columnas = laberinto[0].size();

    vector<vector<int>> visitado(filas, vector<int>(columnas, 0)); // Matriz de nodos visitados
    priority_queue<Nodo, vector<Nodo>, greater<Nodo>> colaPrioridad; // Cola de prioridad para explorar los nodos

    inicio.acumulado = 0; // Inicializa el costo acumulado en el nodo de inicio
    colaPrioridad.push(inicio);

    while (!colaPrioridad.empty()) {
        Nodo actual = colaPrioridad.top(); // Obtiene el nodo con menor costo
        colaPrioridad.pop();

        // Si se alcanza el destino, se retorna el camino encontrado
        if (actual.x == destino.x && actual.y == destino.y) {
            visitado[actual.x][actual.y] = actual.acumulado;
            return visitado;
        }

        // Si el nodo ya fue visitado, se omite
        if (visitado[actual.x][actual.y]) {
            continue;
        }
        visitado[actual.x][actual.y] = actual.acumulado; // Marca el nodo como visitado

        // Intenta avanzar en la dirección actual
        Nodo adelante = actual.avanzar();
        if (adelante.es_valido(laberinto)) {
            adelante.acumulado = actual.acumulado + 1; // Incrementa el costo
            colaPrioridad.push(adelante);
        }

        // Intenta girar a la izquierda y avanzar
        Nodo izquierda = actual.girar(false).avanzar();
        if (izquierda.es_valido(laberinto)) {
            izquierda.acumulado = actual.acumulado + 1001; // Penalización por giro
            colaPrioridad.push(izquierda);
        }

        // Intenta girar a la derecha y avanzar
        Nodo derecha = actual.girar(true).avanzar();
        if (derecha.es_valido(laberinto)) {
            derecha.acumulado = actual.acumulado + 1001; // Penalización por giro
            colaPrioridad.push(derecha);
        }
    }

    return visitado; // No se encontró camino al destino
}

// Función para cargar el laberinto desde un archivo
vector<vector<char>> cargarLaberinto(const string& archivo) {
    vector<vector<char>> laberinto;
    ifstream entrada(archivo);

    if (!entrada.is_open()) {
        cerr << "Error al abrir el archivo: " << archivo << endl;
        return laberinto;
    }

    string linea;
    while (getline(entrada, linea)) {
        vector<char> fila(linea.begin(), linea.end()); // Convierte la línea en un vector de caracteres
        laberinto.push_back(fila);
    }

    entrada.close(); // Cierra el archivo
    return laberinto;
}

int main() {
    string archivoEntrada = "input16.txt"; // Nombre del archivo de entrada
    vector<vector<char>> laberinto = cargarLaberinto(archivoEntrada); // Carga el laberinto

    if (laberinto.empty()) {
        return 1; // Si el archivo no se cargó correctamente, termina el programa
    }

    Nodo inicio, destino; // Nodos para el inicio y el destino

    // Busca las posiciones del inicio ('S') y del destino ('E') en el laberinto
    for (int fila = 0; fila < laberinto.size(); ++fila) {
        for (int col = 0; col < laberinto[0].size(); ++col) {
            if (laberinto[fila][col] == 'S') {
                inicio = Nodo(fila, col, 0, 1, 0); // Dirección inicial al ESTE
            } else if (laberinto[fila][col] == 'E') {
                destino = Nodo(fila, col, 0, 1, 0); // Define el nodo de destino
            }
        }
    }

    auto inicioTiempo = chrono::system_clock::now(); // Marca el inicio del tiempo de ejecución
    vector<vector<int>> resultado = encontrarRuta(laberinto, inicio, destino); // Encuentra la ruta más corta
    auto finTiempo = chrono::system_clock::now(); // Marca el fin del tiempo de ejecución

    int costoFinal = resultado[destino.x][destino.y]; // Obtiene el costo final del destino
    cout << "El coste mínimo para alcanzar el destino es: " << costoFinal << "." << endl; // Imprime el resultado

    return 0; // Termina el programa
}

