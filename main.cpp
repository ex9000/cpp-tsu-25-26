#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Entry {
    int level;
    string key;
    int value;
};

int main() {
    const string filename = "data.kpst";
    vector<Entry> data;

    ifstream infile(filename);
    if (infile.is_open()) {
        string line;
        while (getline(infile, line)) {
            if (line.empty()) continue;

            int level = 0;
            while (level < (int)line.size() && line[level] == '-') {
                level++;
            }

            string rest = line.substr(level);
            istringstream iss(rest);

            string key;
            int value;
            if (iss >> key >> value) {
                data.push_back({level, key, value});
            }
        }
        infile.close();
    }

    string input;
    int value;
    while (cin >> input >> value) {
        int level = 0;
        while (level < (int)input.size() && input[level] == '-') {
            level++;
        }

        string key = input.substr(level);

        bool found = false;
        for (auto& e : data) {
            if (e.level == level && e.key == key) {
                e.value = value;
                found = true;
                break;
            }
        }

        if (!found) {
            data.push_back({level, key, value});
        }
    }

    ofstream outfile(filename);
    if (!outfile.is_open()) {
        cerr << "error\n";
        return 1;
    }

    for (const auto& e : data) {
        for (int i = 0; i < e.level; ++i) {
            outfile << "-";
        }
        outfile << e.key << " " << e.value << "\n";
    }

    outfile.close();
    return 0;
}
