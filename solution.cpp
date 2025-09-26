#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    cout << "Позиций в чеке: " << n << endl;
        
    int total_items = 0;
    int total_price = 0;

    for (int i = 0; i < n; i++) {
        string name1, name2, name3, temp;
        int k, price;

        cin >> name1;
        cin >> name2;
        cin >> name3;
        cin >> temp;
        cin >> price;
        cin >> temp;

        k = 1;

        total_items += k;
        total_price += k * price;

        cout << name1 << " " << name2 << " " << name3 << " за " << price << " рублей" << endl;
    }

    cout << "Куплено " << total_items << " штук товара за " << total_price << " рублей" << endl;

    return 0;
}
