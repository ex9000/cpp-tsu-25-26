#include <iostream>
#include <string>
int main() {
    int n;
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3 >> n;
    int total = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int k, p; 
        std::string word1, word2, word3, word4;
        while (true) {
            std::cin >> word1 >> word2 >> word3 >> word4;
            if (word2 == "за" || k == 1) {
                std::cin >> word1 >> word2 >> p >> word3; 
            } else if (word2 == "по" || k > 1) {
                std::cin >> word1 >> word2 >> p >> word3 >> k >> word4;  
            }
        }
        total += k * p;
        count += k;
    }
    if (n == 1) {
        std::cout << "Куплен товар за " << total << " рублей" << std::endl;
    } else {
        std::cout << "Куплено " << count << "штук товара за " << total << " рублей" << std::endl;
    }
        return 0;
}
