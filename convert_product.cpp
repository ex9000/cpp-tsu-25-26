#include <algorithm>
#include <string>
using namespace std;

struct Index {long long int index; double value; };
struct Product {string name; double prices[100]; };
struct ScoredProduct {string name; double score; };
extern void bubble_sort(Index[], long long int);
extern double median(double[], long long int);

const long long int X = 23;

ScoredProduct convert_product(Product p, long long int k) {
    Index lst[100];
    for (long long int i = 0; i < k; ++i) {
        lst[i].index = i;
        lst[i].value = p.prices[i];
    }

    bubble_sort(lst, k);

    long long int m = (X < k ? X : k);
    double nw_scor[100];
    for (long long int i = 0; i < m; ++i)
        nw_scor[i] = lst[i].value;

    double score_val = median(nw_scor, m);
    return {p.name, score_val};
}
