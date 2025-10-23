#include <bits/stdc++.h>
using namespace std;

struct Index {
    long long int index;
    double value;
};

void bubble_sort(Index arr[], long long int n) {
    bool swapped;
    for (long long int i = 0; i < n - 1; i++) {
        swapped = false;
        for (long long int j = 0; j < n - i - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
