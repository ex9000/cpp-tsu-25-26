double minimum(double arr[], long long int n) {
	double min = arr[0];

	for (long long int i = 0; i < n; i++)
	{
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}