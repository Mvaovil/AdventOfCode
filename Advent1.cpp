#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main() {
    string file_path = "list.txt";

    ifstream file(file_path);
    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo en la ruta: " << file_path << endl;
        return 1;
    }

    vector<int> left_list, right_list;
    int left, right;

    while (file >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    file.close();

    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());

    int total_distance = 0;
    for (size_t i = 0; i < left_list.size(); ++i) {
        total_distance += abs(left_list[i] - right_list[i]);
    }

    cout << "Total Distance: " << total_distance << endl;

    return 0;
}

