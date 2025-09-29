#include <iostream>
#include <string>
int main() {
    int n;
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3 >> n;
    int total = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int k = 1, p = 0;  
        std::string word;
        while (true) {
            std::cin >> word;
            if (word == "за") {
                std::cin >> p >> word; 
                k = 1;  
                break;
            } else if (word == "по") {
                std::cin >> p >> word >> word >> k >> word; 
                break;
            }
        }
        total += k * p;
        count += k;
    }
    if (n == 1) {
        std::cout << "Куплен товар за " << total << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << count << " штук товара за " << total << " рублей" << std::endl;
    }
    return 0;
}
