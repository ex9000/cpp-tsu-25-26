#include <algorithm>

double median(double arr[], long long int n) {
    double temp[100];
    for (long long int i=0; i<n; ++i)
        temp[i] = arr[i];
    std::sort(temp, temp + n);
    if (n % 2 == 1) {
        return temp[n/2];
    } else {
        return (temp[n/2 - 1] + temp[n/2]) / 2.0;
    }
}