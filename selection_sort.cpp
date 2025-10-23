struct Index { long long int index; double value; };
void selection_sort(Index arr[], long long int n) {
    for (long long int i = 0; i < n - 1; i++) {
        long long int mIndex = i;
        for (long long int j = i + 1; j < n; j++) {
            if (arr[j].value < arr[mIndex].value)
                mIndex = j;
        }
        Index temp = arr[i];
        arr[i] = arr[mIndex];
        arr[mIndex] = temp;
    }
}