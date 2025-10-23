double average(double arr[], long long int n) {
    if (n == 0) return 0.0;
    double total = 0.0;
    for (long long int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total / n;
}
