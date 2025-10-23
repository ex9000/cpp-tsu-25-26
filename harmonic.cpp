extern "C" double harmonic(double arr[], long long int n) {
    double sum = 0.0;
    for (long long int i = 0; i < n; ++i)
        sum += 1.0 / arr[i];
    return n / sum;
}
