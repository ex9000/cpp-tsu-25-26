#include <iostream>

int main() {
    int сount;
    std::cout << "Vvesti kol-vo tovarov: ";
    std::cin >> сount; 

    int summa = 0;
    std::cout << "Vvesti tovar(kol-vo price):\n";
    for (int i = 0; i < сount; ++i) {
        int count_tovarov, price;
        std::cin >> count_tovarov >> price;
        summa += count_tovarov * price;
    }

    std::cout << summa << std::endl;

    return 0;
}
