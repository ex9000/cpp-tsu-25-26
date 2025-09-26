#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total = 0;
    int total_items = 0;

    for (int i = 0; i < n; i++) {
        string s;
        int k;
        double p;

        cin >> s >> k >> s >> p >> s;

        total += k * p;
        total_items += k;

        if (k == 1) {
            cout << "Куплен товар за " << p << " рублей" << endl;
        } else {
            cout << "Куплен товар в количестве " << k << " штук за " << p * k << " рублей" << endl;
        }
    }

    cout << "Куплено " << total_items << " штук товара за " << total << " рублей" << endl;

    return 0;
}

