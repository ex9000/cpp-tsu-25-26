#include <iostream>
#include <string>
int main() {
    std::string w1, w2, w3;
    int n;
    std::cin >> w1 >> w2 >> w3 >> n;
    int total_sum = 0;
    int total_count = 0;
    std::string next_word; 
    bool has_next_word = false;
    for (int i = 0; i < n; ++i) {
        int quantity = 1;
        int price = 0;
        std::string word;
        if (has_next_word) {
            word = next_word;
            has_next_word = false;
        } else {
            std::cin >> word;
        }
        while (word != "за" && word != "по") {
            std::cin >> word;
        }
        std::cin >> price;
        std::cin >> word; // слово "рублей"
        if (std::cin >> word) {
            if (word == ":") {
                std::cin >> quantity >> word; // читаем количество и "штуки"
            } else {
                next_word = word;
                has_next_word = true;
            }
        }
        total_sum += price * quantity;
        total_count += quantity;
    }
    if (total_count == 1) {
        std::cout << "Куплен товар за " << total_sum << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << total_count << " штук товара за " << total_sum << " рублей" << std::endl;
    }

    return 0;
}
