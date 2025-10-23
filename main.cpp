#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Index { long long int id; double val; };
struct Product { string title; double costs[100]; };
struct ScoredProduct { string title; double rate; };
extern void read_data(Product[], long long int, long long int);
extern ScoredProduct convert_product(Product, long long int);
extern void selection_sort(Index[], long long int);
extern double product(double[], long long int);

const long long int kp_prod = 17;

int main() {
    long long int totalll, priceCount;
    cin >> totalll >> priceCount;

    Product catalog[100];
    read_data(catalog, totalll, priceCount);

    ScoredProduct rated[100];
    for (long long int i = 0; i < totalll; ++i)
        rated[i] = convert_product(catalog[i], priceCount);

    Index rates[100];
    for (long long int i = 0; i < totalll; ++i) {
        rates[i].id = i;
        rates[i].val = rated[i].rate;
    }

    selection_sort(rates, totalll);

    long long int limit;
    if (kp_prod < totalll)
        limit = kp_prod;
    else
        limit = totalll;

    double chosen[100];
    for (long long int i = 0; i < limit; ++i)
        chosen[i] = rates[i].val;

    double totalRR = product(chosen, limit);

    long long int nearestIdx = 0;
    double minDiff = fabs(rated[0].rate - totalRR);
    for (long long int i = 1; i < totalll; ++i) {
        double diff = fabs(rated[i].rate - totalRR);
        if (diff < minDiff) {
            minDiff = diff;
            nearestIdx = i;
        }
    }

    cout << "Total score: " << (long long)round(totalRR) << endl;
    cout << "Best product: " << rated[nearestIdx].title
         << " (score: " << (long long)round(rated[nearestIdx].rate) << ")" << endl;

    return 0;
}
