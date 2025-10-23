/*
 * Функция harmonic вычисляет гармоническое среднее для массива чисел.
 *
 * Параметры:
 *  - arr: массив чисел
 *  - n: размер массива
 *
 * Возвращает гармоническое среднее: n / (сумма обратных значений массива)
 */
double harmonic(double arr[], long long int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i)
        sum += 1.0 / arr[i];
    return n / sum;
}
