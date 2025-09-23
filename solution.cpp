#include <iostream>
#include <string>
int main() {
    std::string w1, w2, w3;
    int n;
    std::cin >> w1 >> w2 >> w3 >> n; 
    int total_sum = 0;
    int total_count = 0;
    for (int i = 0; i < n; i++) {
        int quantity = 1;
        int price = 0;
        std::string word;
        while (true) {
            std::cin >> word;
            if (word == "за" || word == "по") break;
        }
        if (std::cin >> word) {
            if (word == ":") {
                std::cin >> quantity >> word; // quantity и "штуки"
            } else {
            }
        }
        total_sum += price * quantity;
        total_count += quantity;
    }
    if (total_count == 1) {
        std::cout << "Куплен товар за " << total_sum << " рублей" << endl;
    } else {
        std::cout << "Куплено " << total_count << " штук товара за " << total_sum << " рублей" <<endl;
    }
    return 0;
}
