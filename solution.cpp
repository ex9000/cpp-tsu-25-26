#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp;
    int n;
    cin >> temp >> temp >> temp >> n;
    
    int total_items = 0;
    int total_price = 0;

    for (int i = 0; i < n; i++) {
        string word;
        int k = 1;
        int price;

        while (cin >> word) {
            if (word == "за") {
                cin >> price >> word;
                k = 1;
                break;
            } else if (word == "по") {
                cin >> price >> word;
                cin >> k >> word;
                break;
            }
        }

        total_items += k;
        total_price += k * price;
    }

    if (total_items == 1) {
        cout << "Куплен товар за " << total_price << " рублей" << endl;
    } else {
        cout << "Куплено " << total_items << " штук товара за " << total_price << " рублей" << endl;
    }

    return 0;
}
