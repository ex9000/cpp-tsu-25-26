struct Index {
	long long int index;
	double value;
};

void selection_sort(Index arr[], long long int n) {
	for (long long int i = 0; i < n - 1; i++)
	{
		long long int min_index = i;
		for (long long int j = i + 1; j < n; j++)
		{
			if (arr[j].value < arr[min_index].value) {
				min_index = j;
			}
		}

		Index temp;
		temp.index = arr[i].index;
		temp.value = arr[i].value;

		arr[i].index = arr[min_index].index;
		arr[i].value = arr[min_index].value;
		arr[min_index].index = temp.index;
		arr[min_index].value = temp.value;
	}
}