#include <string>
#include <iostream>

using namespace std;

struct Index {
	long long int index;
	double value;
};

struct Product {
	string name;
	double prices[100];
};

struct ScoredProduct {
	string name;
	double score;
};

void selection_sort(Index arr[], long long int n);

double minimum(double arr[], long long int n);

ScoredProduct convert_product(Product p, long long int k) {
	ScoredProduct res;
	res.name = p.name;

	Index prices[100];
	for (long long int i = 0; i < k; i++)
	{
		prices[i].index = i;
		prices[i].value = p.prices[i];
	}

	selection_sort(prices, k);

	double sorted_prices[17];
	for (long long int i = 0; i < 17; i++)
	{
		sorted_prices[i] = prices[i].value;
	}

	res.score = minimum(sorted_prices, 17);

	return res;
}