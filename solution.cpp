#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // Сбросить символ новой строки после числа

    vector<long long> salaries;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);

        // Найти последнее слово (зарплата)
        size_t last_space = line.find_last_of(' ');
        if (last_space != string::npos) {
            string salary_str = line.substr(last_space + 1);
            long long salary = stoll(salary_str);
            salaries.push_back(salary);
        }
    }

    // Сортировка зарплат
    sort(salaries.begin(), salaries.end());

    // Медиана — это центральный элемент
    cout << salaries[n / 2] << endl;

    return 0;
}
