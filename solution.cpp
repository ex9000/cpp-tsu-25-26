#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    int total = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int k, p;
        std::string w4, w5, w6;
        std::cin >> w4 >> w5 >> w6 >> k >> p;
        if (n == 1) {
            std::cin >> w4 >> p >> w5;
        } else {
            std::cin >> w4 >> p >> w5 >> k >> w6;
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
