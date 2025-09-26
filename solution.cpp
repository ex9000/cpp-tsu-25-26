#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int summa = 0;

    for (int i = 0; i < n; ++i) {
        int count;
        int price;
        std::cin >> count >> price;
        summa += count * price;
    }

    std::cout << "Сумма всех товаров: " << summa << std::endl;

    return 0;
}
