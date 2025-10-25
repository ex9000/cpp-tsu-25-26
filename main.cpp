#include <iostream>
#include <cmath>
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

extern "C" void read_data(Product products[], long long int n, long long int k);
extern "C" ScoredProduct convert_product(Product p, long long int k);
extern "C" void insertion_sort(Index arr[], long long int n);
extern "C" double harmonic(double arr[], long long int n);

int main() {
    long long int n, k;
    std::cin >> n >> k;

    Product products[100];
    read_data(products, n, k);

    ScoredProduct scored[100];
    for (long long int i = 0; i < n; ++i)
        scored[i] = convert_product(products[i], k);

    Index idx[100];
    for (long long int i = 0; i < n; ++i) {
        idx[i].index = i;
        idx[i].value = scored[i].score;
    }

    insertion_sort(idx, n);

    const long long int Y = 3;
    long long int numScores = std::min(Y, n);
    double scoresY[100];
    for (long long int i = 0; i < numScores; ++i)
        scoresY[i] = scored[idx[i].index].score;

    double total = harmonic(scoresY, numScores);

    long long int best_index = 0;
    double best_diff = std::fabs(scored[0].score - total);
    for (long long int i = 1; i < n; ++i) {
        double diff = std::fabs(scored[i].score - total);
        if (diff < best_diff) {
            best_diff = diff;
            best_index = i;
        }
    }

    std::cout << "Total score: " << total << std::endl;
    std::cout << "Best product: " << scored[best_index].name
              << " (score: " << scored[best_index].score << ")" << std::endl;
}
