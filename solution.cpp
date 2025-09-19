#include<iostream>

int main()
{
    int n;
    std::cin >> n;
    int c, p, s;
    for(int i = 0; i<n; i++) {
        std::cin >> c >> p;
        s += c * p;
    }
    std::cout << s << std::endl;
}
