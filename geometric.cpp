#include <bits/stdc++.h>
using namespace std;

double geometric(double arr[], long long int n) {
    double prod = 1.0;
    for (long long int i = 0; i < n; i++) prod *= arr[i];
    return pow(prod, 1.0 / n);
}
