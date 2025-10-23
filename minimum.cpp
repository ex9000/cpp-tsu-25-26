/*
 * Функция minimum вычисляет минимальное значение из массива чисел.
 *
 * Параметры:
 *  - arr: массив чисел
 *  - n: размер массива
 *
 * Возвращает минимальное значение из массива arr.
 */
double minimum(double arr[], long long int n) {
    double min_val = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] < min_val)
            min_val = arr[i];
    return min_val;
}
