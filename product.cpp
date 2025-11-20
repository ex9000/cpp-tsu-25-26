extern "C" double product(double arr[], long long int n) {
    double res = 1.0;
    for (long long int i = 0; i < n; ++i)
        res *= arr[i];
    return res;
}
