#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int n;

    cin >> s >> s >> s >> n;

    int TSum = 0;
    int TCount = 0;

    for (int i = 0; i < n; i++) {
        while (cin >> s) {
            if (s == "за") {
                int price;
                cin >> price;
                cin >> s;
                totalSum += price;
                totalCount += 1;
                break;
            }
            else if (s == "по") {
                int p, k;
                cin >> price;
                cin >> s;
                cin >> count;
                cin >> s;
                TSum += price * count;
                TCount += count;
                break;
            }
        }
    }

    if (TCount == 1) {
        cout << "Куплен товар за " << TSum << " рублей\n";
    } else {
        cout << "Куплено " << TCount << " штук товара за " << TSum << " рублей\n";
    }

    return 0;
}
