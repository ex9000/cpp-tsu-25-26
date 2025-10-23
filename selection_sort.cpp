#include <utility> // для std::swap

// Структура для индекса и значения, используется для сортировки
struct Index {
    long long int index; // исходная позиция элемента
    double value;        // значение для сравнения
};

/*
 * Функция selection_sort сортирует массив Index по возрастанию поля value методом выбора.
 *
 * Параметры:
 *  - arr: массив структур Index
 *  - n: количество элементов в массиве
 */
void selection_sort(Index arr[], long long int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j].value < arr[min_idx].value)
                min_idx = j;
        }
        std::swap(arr[i], arr[min_idx]);
    }
}
