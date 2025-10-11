#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int GetCount() {
    int n;
    cin >> n;
    cin.ignore();
    return n;
}

long long ExtractSalary(const string &line) {
    int pos = line.size() - 1;
    while (pos >= 0 && line[pos] == ' ') pos--;
    int end = pos;
    while (pos >= 0 && isdigit(line[pos])) pos--;
    string salaryStr = line.substr(pos + 1, end - pos);
    return stoll(salaryStr);
}

int main() {
    int n = GetCount();
    string s;
    long long arr[10001];

    for (int i = 0; i < n; i++) {
        getline(cin, s);
        arr[i] = ExtractSalary(s);
    }

    sort(arr, arr + n);
    cout << arr[n / 2] << endl;
    return 0;
}
