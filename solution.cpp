#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int c, p;
    int s = 0;
    for(int i = 0; i<n; i++) {
        std::cin >> c >> p;
        s += c * p;
    }
    std::cout << s << std::endl;
    return 0;
}
