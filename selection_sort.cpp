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



void selection_sort(Index arr[], long long int n) {
    for (long long int i = 0; i < n - 1; i++) {
        long long int min_idx = i;
        for (long long int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_idx].value) {
                min_idx = j;
            }
        }
        Index temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}