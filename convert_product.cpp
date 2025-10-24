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



ScoredProduct convert_product(Product p, long long int k) {
    const long long int X = 21;

    // Создаем массив индексов для сортировки
    Index indices[100];
    for (long long int i = 0; i < k; i++) {
        indices[i].index = i;
        indices[i].value = p.prices[i];
    }

    // Сортируем цены с помощью selection_sort
    selection_sort(indices, k);

    // Выбираем первые X цен после сортировки
    double selected_prices[X];
    for (long long int i = 0; i < X && i < k; i++) {
        selected_prices[i] = indices[i].value;
    }

    // Применяем первую функцию оценки (product)
    double product_score = product(selected_prices, X);

    ScoredProduct result;
    result.name = p.name;
    result.score = product_score;
    return result;
}