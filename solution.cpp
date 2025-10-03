#include <iostream>
#include <string>
using namespace std;

long long parseZp(const string &line) {
    int pos = line.size() - 1;
    while (pos >= 0 and line[pos] == ' ') pos--;
    int end = pos;
    while (pos >= 0 and line[pos] >= '0' and line[pos] <= '9') pos--;

    long long zp = 0;
    for (int i = pos + 1; i <= end; i++) {
        zp = zp * 10 + (line[i] - '0');
    }
    return zp;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    long long salaries[n] = {};

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        salaries[i] = parseZp(line);
    }

    for (int i = 1; i < n; i++) {
        long long key = salaries[i];
        int j = i - 1;
        while (j >= 0 and salaries[j] > key) {
            salaries[j + 1] = salaries[j];
            j--;
        }
        salaries[j + 1] = key;
    }

    cout << salaries[n / 2] << endl;

    return 0;
}
