#include <iostream>
#include <cmath>
#include <string>

// Повторяем структуры для main.cpp
struct Product {
    std::string name;
    double prices[100];
};

struct Index {
    long long int index;
    double value;
};

struct ScoredProduct {
    std::string name;
    double score;
};

// Объявляем внешние функции (определены в других единицах компиляции)
extern void read_data(Product[], long long int, long long int);
extern ScoredProduct convert_product(Product, long long int);
extern void selection_sort(Index[], long long int);
extern double harmonic(double[], long long int);

/*
 * Основная функция программы анализирует цены продуктов
 * по алгоритму из задания:
 * 1. Считать данные с помощью read_data.
 * 2. Получить оценки продуктов с помощью convert_product.
 * 3. Отсортировать продукты по оценкам через selection_sort.
 * 4. Вычислить общую оценку через harmonic.
 * 5. Найти продукт с наиболее близкой оценкой к общей.
 * 6. Вывести результаты.
 */
int main() {
    long long int N, K;
    std::cin >> N >> K;

    Product products[100];
    // Считываем данные
    read_data(products, N, K);

    // Массив оцененных продуктов
    ScoredProduct rated[100];
    for (int i = 0; i < N; ++i) {
        rated[i] = convert_product(products[i], K);
    }

    // Массив индексов для сортировки по оценкам
    Index arr[100];
    for (int i = 0; i < N; ++i) {
        arr[i].index = i;
        arr[i].value = rated[i].score;
    }

    // Сортируем продукты по возрастанию оценок
    selection_sort(arr, N);

    // Собираем оценки для подсчёта общей гармонической оценки
    double vals[100];
    for (int i = 0; i < N; ++i)
        vals[i] = rated[i].score;

    // Вычисляем общую оценку
    double total = harmonic(vals, N);

    // Ищем продукт с оценкой, ближе всего к общей
    int best = arr[0].index;
    double diff = std::abs(rated[best].score - total);
    for (int i = 1; i < N; ++i) {
        double curr_diff = std::abs(rated[arr[i].index].score - total);
        if (curr_diff < diff) {
            diff = curr_diff;
            best = arr[i].index;
        }
    }

    // Выводим результаты
    std::cout << "Total score: " << total << std::endl;
    std::cout << "Best product: " << rated[best].name
              << " (score: " << rated[best].score << ")" << std::endl;

    return 0;
}
