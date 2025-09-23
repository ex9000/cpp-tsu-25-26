#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    int total = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int k, p;
        std::string w1, w2, w3;
        std::cin >> w1 >> w2 >> w3 >> k >> p;
        if (n == 1) {
            std::cin >> w1 >> p >> w2;
        } else {
            std::cin >> w1 >> p >> w2 >> k >> w3;
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
