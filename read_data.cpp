#include <iostream>
#include <string>

// Структура для хранения продукта и его цен
struct Product {
    std::string name;      // название продукта
    double prices[100];    // массив цен продукта
};

/*
 * Функция read_data читает данные о продуктах из стандартного ввода.
 *
 * Параметры:
 *  - products: массив для хранения продуктов
 *  - n: количество продуктов
 *  - k: количество цен для каждого продукта
 *
 * Функция считывает для каждого продукта имя и k цен, записывая их в products.
 */
void read_data(Product products[], long long int n, long long int k) {
    for (int i = 0; i < n; ++i) {
        std::cin >> products[i].name;
        for (int j = 0; j < k; ++j)
            std::cin >> products[i].prices[j];
    }
}
