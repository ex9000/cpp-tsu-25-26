struct Index {
	long long int index;
	double value;
};

void bubble_sort(Index arr[], long long int n) {
	for (long long int i = 0; i < n - 1; i++) {
		for (long long int j = 0; j < n - i - 1; j++) {
			if (arr[j].value > arr[j + 1].value) {
				Index temp;
				temp.index = arr[j].index;
				temp.value = arr[j].value;

				arr[j].index = arr[j + 1].index;
				arr[j].value = arr[j + 1].value;
				arr[j + 1].index = temp.index;
				arr[j + 1].value = temp.value;
			}
		}
	}
}