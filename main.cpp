#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>

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
double average(double arr[], long long int n);

int main() {
    long long int n, k;
    cin >> n >> k;

    Product products[100];
    read_data(products, n, k);


    ScoredProduct Scored[100];
    for (long long int i = 0; i < n; i++) {
        Scored[i] = convert_product(products[i], k);
    }

    Index score_in_indexes_prepare[100];
    for (long long int i = 0; i < n; i++) {
        score_in_indexes_prepare[i].index = i;
        score_in_indexes_prepare[i].value = Scored[i].score;
    }
    bubble_sort(score_in_indexes_prepare, n);


    double scores_after_sort2[11];
    for (int i = 0; i < 11; i++) {
        scores_after_sort2[i] = score_in_indexes_prepare[i].value;
    }

    double scores_2 = average(scores_after_sort2, 11);

    long long int ResultInd = -1;
    double minDiff = DBL_MAX;

    for (int i = 0; i < 7; i++) {
        double diff = abs(Scored[i].score - scores_2);
        if (diff < minDiff) {
            minDiff = diff;
            ResultInd = i;
        }
    }

    cout << "Total score: " << scores_2 << std::endl;
    cout << "Best product: " << Scored[ResultInd].name
        << " (score: " << Scored[ResultInd].score << ")" << endl;

    return 0;

}
