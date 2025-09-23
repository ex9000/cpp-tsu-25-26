#include <iostream>
#include <string>
int main() {
    std::string w1, w2, w3;
    int n;
    std::cin >> w1 >> w2 >> w3 >> n; 
    int total = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::string name, word4, word5;
        int price = 0;
        int quantity = 1; 
        std::cin >> name >> word4 >> price >> word5;
        if (n > 1) {
            if (std::cin >> quantity) {
                std::string unit;
                std::cin >> unit;
            } else {
                quantity = 1;
            }
        }
        total += price * quantity;
        count += quantity;
    }
    if (n == 1) {
        std::cout << w1 << price << w2 << std::endl;
    } else {
        std::cout << w1 << k << w2 << total << w3 << std::endl;
    }
    return 0;
}
