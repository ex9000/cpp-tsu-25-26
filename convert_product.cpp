#include <string>

// Структуры, используемые в функции
struct Product {
    std::string name;
    double prices[100];
};

struct ScoredProduct {
    std::string name;
    double score;
};

// Прототип функции minimum (импортируется из другого файла)
extern double minimum(double arr[], long long int n);

/*
 * Функция convert_product конвертирует продукт в структуру с оценкой.
 *
 * Параметры:
 *  - p: продукт для оценки
 *  - k: количество цен для продукта
 *
 * Использует функцию minimum для оценки продукта по минимальной цене.
 * Возвращает структуру с именем продукта и рассчитанным score.
 */
ScoredProduct convert_product(Product p, long long int k) {
    double score = minimum(p.prices, k);
    return {p.name, score};
}
