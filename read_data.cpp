#include <iostream>

struct Product {
    std::string name;
    double prices[100];
};

extern "C" void read_data(Product products[], long long int n, long long int k) {
    for (long long int i = 0; i < n; ++i) {
        std::cin >> products[i].name;
        for (long long int j = 0; j < k; ++j)
            std::cin >> products[i].prices[j];
    }
}
