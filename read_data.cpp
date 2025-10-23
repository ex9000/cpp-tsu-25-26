#include <iostream>
#include <string>

struct Index {
    long long int index;
    double value;
};

struct Product {
    std::string name;
    double prices[100];
};

struct ScoredProduct {
    std::string name;
    double score;
};

void read_data(Product* products, long long int& n, long long int& k);

void read_data(Product* products, long long int& n, long long int& k) {
    std::cin >> n >> k;
    for (long long int i=0; i<n; ++i) {
        std::cin >> products[i].name;
        for (long long int j=0; j<k; ++j) {
            std::cin >> products[i].prices[j];
        }
    }
}