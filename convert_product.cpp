#include <string>

using namespace std;
struct Index { long long int index; double value; };
struct Product { string name; double prices[100]; };
struct ScoredProduct { string name; double score; };

void selection_sort(Index arr[], long long int n);
double average(double arr[], long long int n);

ScoredProduct convert_product(Product p, long long int k) {
    ScoredProduct Result;
    Result.name = p.name;

    Index indexes[100];
    for (long long int i = 0; i < k; i++) {
        indexes[i].index = i;
        indexes[i].value = p.prices[i];
    }

    selection_sort(indexes, k);

    double top_prices[7];
    for (long long int i = 0; i < 7; i++) {
        top_prices[i] = indexes[i].value;
    }

    Result.score = average(top_prices, 7);
    return Result;
}