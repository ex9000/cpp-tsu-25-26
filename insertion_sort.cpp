#include <bits/stdc++.h>
#include "structs.h"
using namespace std;

void insertion_sort(Index arr[], long long int n) {
    for (long long int i = 1; i < n; i++) {
        Index key = arr[i];
        long long int j = i - 1;
        while (j >= 0 && arr[j].value > key.value) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
