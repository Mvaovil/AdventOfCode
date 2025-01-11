#include <iostream>
#include <vector>
#include <map> 

using namespace std;

bool esActualizacionValida(const vector<int>& actualizacion, const map<int, vector<int> >& grafo) {
    map<int, int> indice;
    for (int i = 0; i < actualizacion.size(); ++i) {
        indice[actualizacion[i]] = i;
    }
    for (map<int, vector<int> >::const_iterator it = grafo.begin(); it != grafo.end(); ++it) {
        int pagina = it->first;
        const vector<int>& vecinos = it->second;
        for (int i = 0; i < vecinos.size(); ++i) {
            int vecino = vecinos[i];
            if (indice.count(pagina) && indice.count(vecino) && indice[pagina] >= indice[vecino]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
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

    map<int, vector<int> > grafo;
    for (int i = 0; i < reglas.size(); ++i) {
        grafo[reglas[i].first].push_back(reglas[i].second);
    }

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

    for (int i = 0; i < actualizaciones.size(); ++i) {
        if (esActualizacionValida(actualizaciones[i], grafo)) {
            int centro = actualizaciones[i][actualizaciones[i].size() / 2];
            sumaDeCentros += centro;
        }
    }

    cout << "Suma de páginas centrales: " << sumaDeCentros << endl;

    return 0;
}

