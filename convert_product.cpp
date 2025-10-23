#include <string>
#include "header.h"

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

void bubble_sort(Index arr[], long long int n);

ScoredProduct convert_product(const Product& p, long long int k) {
    Index indices[100];
    for (long long int i=0; i<k; ++i) {
        indices[i].index = i;
        indices[i].value = p.prices[i];
    }

    bubble_sort(indices, k);

    double arr[100];
    for (long long int i=0; i<k; ++i) {
        arr[i] = p.prices[i];
    }

    double score_value = median(arr, k);

    return {p.name, score_value};
}