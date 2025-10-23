double sum(double arr[], long long int n) {
    double result = 0.0;
    for (long long int i = 0; i < n; i++) {
        result += arr[i];
    }
    return result;
}
