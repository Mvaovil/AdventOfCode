#include <iostream>
#include <vector>
#include <map> 

using namespace std;

// Con esta unción, verificamos si una actualización de páginas es válida según las reglas del grafo
bool esActualizacionValida(const vector<int>& actualizacion, const map<int, vector<int> >& grafo) {
    // Creamos un mapa que almacene el índice de cada página en la actualización
    map<int, int> indice;
    for (int i = 0; i < actualizacion.size(); ++i) {
        indice[actualizacion[i]] = i;  // Asocia la página a su índice en la actualización
    }
    
    // Recorremos todas las páginas en el grafo y verificamos si las relaciones entre ellas son válidas
    for (map<int, vector<int> >::const_iterator it = grafo.begin(); it != grafo.end(); ++it) {
        int pagina = it->first;
        const vector<int>& vecinos = it->second;
        
        // Comprobamos la relación de cada página con sus vecinos
        for (int i = 0; i < vecinos.size(); ++i) {
            int vecino = vecinos[i];
            
            // Si ambas páginas (la actual y su vecino) están presentes en la actualización, verificamos si la página esta antésacristía que la de su vecino
            if (indice.count(pagina) && indice.count(vecino) && indice[pagina] >= indice[vecino]) {
                return false;  // Si la página aparece después de su vecino, la actualización no es válida
            }
        }
    }
    return true;  // Si todas las relaciones son válidas, la actualización es válida
}

int main() {
    // Definir las reglas que especifican las relaciones entre las páginas según el ejercicio propuesto 
    vector<pair<int, int> > reglas;
    reglas.push_back(make_pair(47, 53));
    reglas.push_back(make_pair(97, 13));
    reglas.push_back(make_pair(97, 61));
    reglas.push_back(make_pair(97, 47));
    reglas.push_back(make_pair(75, 29));
    reglas.push_back(make_pair(61, 13));
    reglas.push_back(make_pair(75, 53));
    reglas.push_back(make_pair(29, 13));
    reglas.push_back(make_pair(97, 29));
    reglas.push_back(make_pair(53, 29));
    reglas.push_back(make_pair(61, 53));
    reglas.push_back(make_pair(97, 53));
    reglas.push_back(make_pair(61, 29));
    reglas.push_back(make_pair(47, 13));
    reglas.push_back(make_pair(75, 47));
    reglas.push_back(make_pair(97, 75));
    reglas.push_back(make_pair(47, 61));
    reglas.push_back(make_pair(75, 61));
    reglas.push_back(make_pair(47, 29));
    reglas.push_back(make_pair(75, 13));
    reglas.push_back(make_pair(53, 13));

    // Creamos el grafo representando las relaciones de dependencias entre páginas
    map<int, vector<int> > grafo;
    for (int i = 0; i < reglas.size(); ++i) {
        grafo[reglas[i].first].push_back(reglas[i].second);  // Añadimos las relaciones al grafo
    }

    // Definimos una lista de actualizaciones que contienen secuencias de páginas
    vector<vector<int> > actualizaciones;
    vector<int> actualizacion1; actualizacion1.push_back(75); actualizacion1.push_back(47); actualizacion1.push_back(61); actualizacion1.push_back(53); actualizacion1.push_back(29);
    vector<int> actualizacion2; actualizacion2.push_back(97); actualizacion2.push_back(61); actualizacion2.push_back(53); actualizacion2.push_back(29); actualizacion2.push_back(13);
    vector<int> actualizacion3; actualizacion3.push_back(75); actualizacion3.push_back(29); actualizacion3.push_back(13);
    vector<int> actualizacion4; actualizacion4.push_back(75); actualizacion4.push_back(97); actualizacion4.push_back(47); actualizacion4.push_back(61); actualizacion4.push_back(53);
    vector<int> actualizacion5; actualizacion5.push_back(61); actualizacion5.push_back(13); actualizacion5.push_back(29);
    vector<int> actualizacion6; actualizacion6.push_back(97); actualizacion6.push_back(13); actualizacion6.push_back(75); actualizacion6.push_back(29); actualizacion6.push_back(47);
    actualizaciones.push_back(actualizacion1);
    actualizaciones.push_back(actualizacion2);
    actualizaciones.push_back(actualizacion3);
    actualizaciones.push_back(actualizacion4);
    actualizaciones.push_back(actualizacion5);
    actualizaciones.push_back(actualizacion6);

    int sumaDeCentros = 0;

    // Recorremos todas las actualizaciones y verificamos si son válidas
    for (int i = 0; i < actualizaciones.size(); ++i) {
        if (esActualizacionValida(actualizaciones[i], grafo)) {
            // Si la actualización es válida, sumar el valor de la página central
            int centro = actualizaciones[i][actualizaciones[i].size() / 2];
            sumaDeCentros += centro;
        }
    }

    // Imprimir la suma de las páginas centrales de las actualizaciones válidas (Debería salir 143)
    cout << "Suma de páginas centrales: " << sumaDeCentros << endl;

    return 0;
}
