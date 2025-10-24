#include <iostream>
#include <cmath>
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

// Общие функции
void read_data(Product products[], long long int n, long long int k);
ScoredProduct convert_product(Product p, long long int k);

// Функции сортировки
void selection_sort(Index arr[], long long int n);

// Функции оценки
double product(double arr[], long long int n);
double maximum(double arr[], long long int n);


int main() {
    long long int n, k;
    std::cin >> n >> k;

    // Чтение данных
    Product products[100];
    read_data(products, n, k);

    // Преобразование продуктов с помощью convert_product
    ScoredProduct scored_products[100];
    for (long long int i = 0; i < n; i++) {
        scored_products[i] = convert_product(products[i], k);
    }

    // Сортировка продуктов по оценке с помощью selection_sort
    Index score_indices[100];
    for (long long int i = 0; i < n; i++) {
        score_indices[i].index = i;
        score_indices[i].value = scored_products[i].score;
    }

    selection_sort(score_indices, n);

    // Выбор Y товаров после сортировки
    const long long int Y = 7;
    double top_scores[Y];
    for (long long int i = 0; i < Y && i < n; i++) {
        top_scores[i] = scored_products[score_indices[i].index].score;
    }

    // Применение второй функции оценки (maximum) для получения общей оценки
    double total_score = maximum(top_scores, Y);

    // Поиск продукта с оценкой, наиболее близкой к общей
    double min_diff = -1;
    ScoredProduct best_product;
    for (long long int i = 0; i < n; i++) {
        double diff = std::abs(scored_products[i].score - total_score);
        if (min_diff < 0 || diff < min_diff) {
            min_diff = diff;
            best_product = scored_products[i];
        }
    }

    // Вывод результатов
    std::cout << "Total score: " << total_score << std::endl;
    std::cout << "Best product: " << best_product.name << " (score: " << best_product.score << ")" << std::endl;

    return 0;
}
