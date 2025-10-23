#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

extern void read_data(Product products[], long long int n, long long int k);
extern ScoredProduct convert_product(Product p, long long int k);
extern void bubble_sort(Index arr[], long long int n);
extern double geometric(double arr[], long long int n);

int main() {
    long long int N, K;
    cin >> N >> K;

    Product products[100];
    read_data(products, N, K);

    ScoredProduct scored[100];
    for (long long int i = 0; i < N; i++) {
        scored[i] = convert_product(products[i], K);
    }

    Index idx[100];
    for (long long int i = 0; i < N; i++) {
        idx[i].index = i;
        idx[i].value = scored[i].score;
    }
    bubble_sort(idx, N);

    long long int newN = min(5LL, N); // Y = 5 из твоего варианта
    double scores[100];
    for (long long int i = 0; i < newN; i++) {
        scores[i] = idx[i].value;
    }

    double total_score = geometric(scores, newN);

    double best_diff = 1e18;
    string best_name;
    double best_score;
    for (long long int i = 0; i < N; i++) {
        double diff = fabs(scored[i].score - total_score);
        if (diff < best_diff) {
            best_diff = diff;
            best_name = scored[i].name;
            best_score = scored[i].score;
        }
    }

    cout << "Total score: " << total_score << endl;
    cout << "Best product: " << best_name << " (score: " << best_score << ")" << endl;

    return 0;
}
