#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    string "Позиций в чеке: n";
    int total = 0;
    for(int i; i < n, i++) {
        int k, p;
        std::cin >> k >> p;
        string " k штуки";
        string "за p рублей";
        total += k * p;
    }
    if (n == 1) {
        std::cout << "Куплен товар за p рублей" << endl;
    } else {
        std::cout << "Куплено k штук товара за p рублей" << endl;
    }
    return 0;
}
