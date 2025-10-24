#include <iostream>
#include <string>

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

void read_data(Product products[], long long int n, long long int k);

ScoredProduct convert_product(Product p, long long int k);

void bubble_sort(Index arr[], long long int n);

double minimum(double arr[], long long int n);

int main() {
	long long int n, k;
	cin >> n >> k;

	Product products[100];

	read_data(products, n, k);

	ScoredProduct scored_products[100];
	for (long long int i = 0; i < n; i++)
	{
		scored_products[i] = convert_product(products[i], k);
	}

	Index scores[100];
	for (long long int i = 0; i < n; i++)
	{
		scores[i].index = i;
		scores[i].value = scored_products[i].score;
	}

	bubble_sort(scores, n);

	double sorted_scores[17];
	for (long long int i = 0; i < 17; i++)
	{
		sorted_scores[i] = scores[i].value;
	}

	double total_score = minimum(sorted_scores, 17);

	ScoredProduct best_product;
	best_product.name = scored_products[scores[0].index].name;
	best_product.score = sorted_scores[0];

	for (long long int i = 0; i < 17; i++)
	{
		if (abs(total_score - sorted_scores[i]) < abs(total_score - best_product.score)) {
			best_product.name = scored_products[scores[i].index].name;
			best_product.score = sorted_scores[i];
		}
	}

	cout << "Total score: " << total_score << endl;
	cout << "Best product: " << best_product.name << " (score: " << best_product.score << ")" << endl;
}