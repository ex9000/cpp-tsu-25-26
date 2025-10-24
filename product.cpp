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



double product(double arr[], long long int n) {
    double result = 1.0;
    for (long long int i = 0; i < n; i++) {
        result *= arr[i];
    }
    return result;
}