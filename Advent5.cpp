#include <iostream>
#include <vector>
#include <map> 

using namespace std;

// Función para comprobar la validez de la actualización 
bool isValidUpdate(const vector<int>& update, const map<int, vector<int> >& graph) {
    map<int, int> index; // Mapear página -> índice en la actualización
    for (int i = 0; i < update.size(); ++i) {
        index[update[i]] = i;
    }
    for (map<int, vector<int> >::const_iterator it = graph.begin(); it != graph.end(); ++it) {
        int page = it->first;
        const vector<int>& neighbors = it->second;
        for (int i = 0; i < neighbors.size(); ++i) {
            int neighbor = neighbors[i];
            if (index.count(page) && index.count(neighbor) && index[page] >= index[neighbor]) {
                return false; // Regla violada
            }
        }
    }
    return true;
}

int main() {
    // Reglas de ordenamiento 
    vector<pair<int, int> > rules;
    rules.push_back(make_pair(47, 53));
    rules.push_back(make_pair(97, 13));
    rules.push_back(make_pair(97, 61));
    rules.push_back(make_pair(97, 47));
    rules.push_back(make_pair(75, 29));
    rules.push_back(make_pair(61, 13));
    rules.push_back(make_pair(75, 53));
    rules.push_back(make_pair(29, 13));
    rules.push_back(make_pair(97, 29));
    rules.push_back(make_pair(53, 29));
    rules.push_back(make_pair(61, 53));
    rules.push_back(make_pair(97, 53));
    rules.push_back(make_pair(61, 29));
    rules.push_back(make_pair(47, 13));
    rules.push_back(make_pair(75, 47));
    rules.push_back(make_pair(97, 75));
    rules.push_back(make_pair(47, 61));
    rules.push_back(make_pair(75, 61));
    rules.push_back(make_pair(47, 29));
    rules.push_back(make_pair(75, 13));
    rules.push_back(make_pair(53, 13));
// Construcción del grafo
    map<int, vector<int> > graph;
    for (int i = 0; i < rules.size(); ++i) {
        graph[rules[i].first].push_back(rules[i].second);
    }

    vector<vector<int> > updates;
    vector<int> update1; update1.push_back(75); update1.push_back(47); update1.push_back(61); update1.push_back(53); update1.push_back(29);
    vector<int> update2; update2.push_back(97); update2.push_back(61); update2.push_back(53); update2.push_back(29); update2.push_back(13);
    vector<int> update3; update3.push_back(75); update3.push_back(29); update3.push_back(13);
    vector<int> update4; update4.push_back(75); update4.push_back(97); update4.push_back(47); update4.push_back(61); update4.push_back(53);
    vector<int> update5; update5.push_back(61); update5.push_back(13); update5.push_back(29);
    vector<int> update6; update6.push_back(97); update6.push_back(13); update6.push_back(75); update6.push_back(29); update6.push_back(47);
    updates.push_back(update1);
    updates.push_back(update2);
    updates.push_back(update3);
    updates.push_back(update4);
    updates.push_back(update5);
    updates.push_back(update6);

    int sumOfMiddles = 0;

    for (int i = 0; i < updates.size(); ++i) {
        if (isValidUpdate(updates[i], graph)) {
            int middle = updates[i][updates[i].size() / 2];
            sumOfMiddles += middle;
        }
    }

    cout << "Suma de páginas centrales: " << sumOfMiddles << endl;

    return 0;
}
