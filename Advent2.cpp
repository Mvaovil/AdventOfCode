#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

bool seguro(const vector<int>& report) {
    vector<int> diffs;
    for (size_t i = 0; i < report.size() - 1; ++i) {
        int diff = report[i + 1] - report[i];
        diffs.push_back(diff);
    }

    bool strictly_increasing = all_of(diffs.begin(), diffs.end(), [](int diff) {
        return diff >= 1 && diff <= 3;
    });

    bool strictly_decreasing = all_of(diffs.begin(), diffs.end(), [](int diff) {
        return diff <= -1 && diff >= -3;
    });

    return strictly_increasing || strictly_decreasing;
}

int main() {
    string file_path = "list2.txt";
    ifstream file(file_path);

    if (!file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo en la ruta: " << file_path << endl;
        return 1;
    }

    vector<vector<int>> reports;
    string line;

    while (getline(file, line)) {
        vector<int> report;
        istringstream iss(line);
        int num;
        while (iss >> num) {
            report.push_back(num);
        }
        reports.push_back(report);
    }

    int safe_count = 0;
    for (const auto& report : reports) {
        if (seguro(report)) {
            ++safe_count;
        }
    }

    cout << "Safe Count: " << safe_count << endl;

    return 0;
}

