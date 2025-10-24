#include <string>
#include <iostream>

using namespace std;

struct Product {
	string name;
	double prices[100];
};

void read_data(Product products[], long long int n, long long int k) {
	string name;
	double price;

	for (long long int i = 0; i < n; i++)
	{
		cin >> name;
		products[i].name = name;

		for (long long int j = 0; j < k; j++)
		{
			cin >> price;
			products[i].prices[j] = price;
		}
	}
}