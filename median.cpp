#include <algorithm>
using namespace std;

double median(double arr[], long long int n) {
    if (n <= 0) return 0.0;
    sort(arr, arr + n);
    
    if (n % 2) return arr[n/2];
    double med = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    return med;
}
