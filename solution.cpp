#include <iostream>
#include <string>
int main() {
    int n;
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3 >> n;
    int total = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        std::string word;
        while (std::cin >> word) {
            if (word == "за" || word == "по") break;
        }
        int p = 0;
        int k = 1; 
        std::cin >> p;
        if (word == "по") {
            std::cin >> k >> word;
        } else {
        }
        total += p * k;
        count += k;
    }
    if (count == 1) {
        std::cout << "Куплен товар за " << total << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << count << " штук товара за " << total << " рублей" << std::endl;
    }
    return 0;
}
