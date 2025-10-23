struct Index {
    long long int index;
    double value;
};

void selection_sort(Index arr[], long long int n) {
    for (long long int i = 0; i < n - 1; i++) {
        long long int min_index = i;
        for (long long int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[min_index].value) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Index temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
