#include <iostream>

int main()
{
    int N = 0;
    std::cin >> N;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int k, p;
        std::cin >> k >> p;
        sum += k * p;
    }

    std::cout << sum << std::endl;

    return 0;
}