#include <iostream>
#include <string>
int main() {
    int n;
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3 >> n;
    int total = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        int k, p;
        std::string w4, w5, w6, w7;
        std::cin >> w4 >> w5 >> w6;
        if (n == 1) {
            std::cin >> w4 >> p >> w5 >> w6;
        } else {
            std::cin >> w4 >> w5 >> p >> w6 >> k >> w7;
        }
    total += k * p;
    count += k;
    }
    if (n == 1) {
        std::cout << w1 << total << w2 << std::endl;
    } else {
        std::cout << w1 << count << w2 << total << w3 << std::endl;
    }
return 0;
