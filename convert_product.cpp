#include <string>
#include <algorithm>

struct Product {
    std::string name;
    double prices[100];
};

struct ScoredProduct {
    std::string name;
    double score;
};

struct Index {
    long long int index;
    double value;
};

extern "C" void insertion_sort(Index arr[], long long int n);
extern "C" double product(double arr[], long long int n);

extern "C" ScoredProduct convert_product(Product p, long long int k) {
    Index idx[100];
    for (long long int i = 0; i < k; ++i) {
        idx[i].index = i;
        idx[i].value = p.prices[i];
    }

    insertion_sort(idx, k);

    const long long int X = 29;
    long long int numSelected = std::min(X, k);
    double selected[100];
    for (long long int i = 0; i < numSelected; ++i)
        selected[i] = idx[i].value;

    ScoredProduct result;
    result.name = p.name;
    result.score = product(selected, numSelected);
    return result;
}
