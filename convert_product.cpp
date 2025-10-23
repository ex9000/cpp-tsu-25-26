#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

extern void insertion_sort(Index arr[], long long int n);
extern double product(double arr[], long long int n);

ScoredProduct convert_product(Product p, long long int k) {
    Index idx[100];
    for (long long int i = 0; i < k; i++) {
        idx[i].index = i;
        idx[i].value = p.prices[i];
    }

    insertion_sort(idx, k);

    long long int newK = min(9LL, k); // X = 9 из твоего варианта
    double sorted_prices[100];
    for (long long int i = 0; i < newK; i++) {
        sorted_prices[i] = idx[i].value;
    }

    ScoredProduct sp;
    sp.name = p.name;
    sp.score = product(sorted_prices, newK);
    return sp;
}
