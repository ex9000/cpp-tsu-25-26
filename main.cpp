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

void read_data(Product products[], long long int n, long long int k);
ScoredProduct convert_product(Product p, long long int k);
void selection_sort(Index arr[], long long int n);
double average(double arr[], long long int n);

int main() {
    long long int N, K;
    std::cin >> N >> K;
    
    Product products[100];
    read_data(products, N, K);
    
    ScoredProduct scored_products[100];
    for (long long int i = 0; i < N; i++) {
        scored_products[i] = convert_product(products[i], K);
    }
    
    Index scored_indexes[100];
    for (long long int i = 0; i < N; i++) {
        scored_indexes[i].index = i;
        scored_indexes[i].value = scored_products[i].score;
    }
    
    selection_sort(scored_indexes, N);
    
    double top_scores[5];
    long long int Y = 5;
    long long int count = (N < Y) ? N : Y;
    for (long long int i = 0; i < count; i++) {
        long long int idx = scored_indexes[N - 1 - i].index;
        top_scores[i] = scored_products[idx].score;
    }
    
    double total_score = average(top_scores, count);
    
    double min_diff = 1e9;
    ScoredProduct best_product;
    for (long long int i = 0; i < N; i++) {
        double diff = std::abs(scored_products[i].score - total_score);
        if (diff < min_diff) {
            min_diff = diff;
            best_product = scored_products[i];
        }
    }
    
    std::cout << "Total score: " << total_score << std::endl;
    std::cout << "Best product: " << best_product.name << " (score: " << best_product.score << ")" << std::endl;
    
    return 0;
}
