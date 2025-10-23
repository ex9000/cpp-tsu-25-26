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

void selection_sort(Index arr[], long long int n);
double sum(double arr[], long long int n);

ScoredProduct convert_product(Product p, long long int k) {
    const long long int X = 19;
    
    Index indexes[100];
    for (long long int i = 0; i < k; i++) {
        indexes[i].index = i;
        indexes[i].value = p.prices[i];
    }
    
    selection_sort(indexes, k);
    
    double selected_prices[100];
    long long int count = (k < X) ? k : X;
    for (long long int i = 0; i < count; i++) {
        selected_prices[i] = indexes[i].value;
    }
    
    double total = sum(selected_prices, count);
    
    ScoredProduct result;
    result.name = p.name;
    result.score = total;
    return result;
}
