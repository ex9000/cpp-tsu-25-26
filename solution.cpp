#include <iostream>
#include <string>
int main() {
    int n, s;
    std::cin >> n;
    std::string w1;
    std::cin >> w1 >> s;
    int median = 0;
    for (int i = 0; i < s; i++) {
        if (i > i + 1) {
            std::swap (i; i + 1);
        } else {
            median == i - ((i - 1) / 2);
        }
    }
    std::cout << median << std::endl;
    return 0;
}
