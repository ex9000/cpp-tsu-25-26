#include <iostream>
#include <string>

using namespace std;

int main() {
    int total = 0;
    int totaltovars = 0;
    int n;
    string temp;

    cin >> temp >> temp >> temp >> n;

    while (n > 0) {
        int pricetovar, kolvo;
        string ind;

        cin >> ind;
        if (ind == "за") {
            cin >> pricetovar;
            total += pricetovar;
            totaltovars++;
            n--;
        }

        if (ind == "по") {
            cin >> pricetovar >> temp >> kolvo;
            total += kolvo * pricetovar
            ;
            totaltovars += kolvo;
            n--;
        }
    }

    if (totaltovars == 1) {
        cout << "Куплен товар за " << total << " рублей" << endl;
    } else {
        cout << "Куплено " << totaltovars << " штук товара за " << total << " рублей" << endl;
    }
    return 0;
}
