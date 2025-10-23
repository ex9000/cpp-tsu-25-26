#include <iostream>
#include <string>
#include <cmath> 

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
ScoredProduct convert_product(const Product& p, long long int k);
void bubble_sort(Index arr[], long long int n);
double median(double arr[], long long int n);
double sum(double arr[], long long int n);

int main() {
    long long int N, K;
    Product products[100];

    read_data(products, N, K);

    ScoredProduct scored_products[100];
    for (long long int i=0; i<N; ++i) {
        scored_products[i] = convert_product(products[i], K);
    }

    Index indices[100];
    for (long long int i=0; i<N; ++i) {
        indices[i].index = i;
        indices[i].value = scored_products[i].score;
    }

    bubble_sort(indices, N);

    double total_score = 0;
    double scores_arr[100];
    for (long long int i=0; i<N; ++i) {
        scores_arr[i] = scored_products[i].score;
    }
    total_score = sum(scores_arr, N);

    double min_diff = std::abs(scored_products[indices[0].index].score - total_score);
    int best_idx = indices[0].index;
    for (long long int i=1; i<N; ++i) {
        double diff = std::abs(scored_products[indices[i].index].score - total_score);
        if (diff < min_diff) {
            min_diff = diff;
            best_idx = indices[i].index;
        }
    }

    std::cout << "Total score: " << total_score << "\n";
    std::cout << "Best product: " << scored_products[best_idx].name
              << " (score: " << scored_products[best_idx].score << ")\n";

    return 0;
}