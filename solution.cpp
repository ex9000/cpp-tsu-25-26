#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, str3;
    int n;
    cin >> str1 >> str2 >> str3 >> n;
    cin.ignore();

    int TSum = 0;
    int TCount = 0;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        int start1 = line.find_first_of("0123456789");
        int end1 = line.find_first_not_of("0123456789", start1);
        int num_1 = stoi(line.substr(start1, end1 - start1));

        int end2 = line.find_last_of("0123456789");
        int start2 = line.find_last_not_of("0123456789", end2) + 1;
        int num_2 = stoi(line.substr(start2, end2 - start2 + 1));

        int p, k;
        if (line.find("за") != string::npos) {
            p = num_1;
            k = 1;
        } else {
            p = num_1;
            k = num_2;
        }

        TSum += k * p;
        TCount += k;
    }

    if (TCount == 1) {
        cout << "Куплен товар за " << TSum << " рублей" << endl;
    } else {
        cout << "Куплено " << TCount << " штук товара за " << TSum << " рублей" << endl;
    }

    return 0;
}
