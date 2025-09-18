#include <iostream>
#include <string>
int main() {
    std::string line;
    std::getline(std::cin, line);
    int total_sum = 0;
    int total_k = 0;
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, line);
        int k = 1;
        int p = 0;
        std::size_t pos_za = line.find(" за ");
        std::size_t pos_po = line.find(" по ");
        total_sum += k * p;
        total_k += k;
    }
    if (total_k == 1) {
        std::cout << "Куплен товар за " << total_sum << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << total_k << " штук товара за " << total_sum << " рублей" << std::endl;
    }

    return 0;
}
