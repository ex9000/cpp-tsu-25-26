#include <string>
using namespace std;

struct Product {
        std::string name;     // название продукта
        double prices[100];   // цены
    };
struct ScoredProduct { std::string name; double score; };
struct Index { long long int index; double value; };

int main() {
    long long int n,k;
    cin>>n;
    cin>>k;
    Product products[n];
    read_data(products, n, k);
    ScoredProduct scored_products[n];
    for(int i =0;i<n;i++){
        scored_products[i] = convert_product(products[i], k);
    }
    Index scores_indices[n];
    for (long long int i = 0; i < n; i++) {
        scores_indices[i].index = i;
        scores_indices[i].value = scored_products[i].score;
    }
    bubble_sort(scores_indices, n);
    ScoredProduct best_products[21];
    for (int i = 0; i < 21;i++) {
        best_products[i] = scored_products[scores_indices[i].index];
    }
    double scores[21];
    for(int i = 0; i < 21; i++){
        scores[i] = best_products[i].score;
    }
    double total_score = sum(scores, 21);
    
    cout<<"Total score: "<<total_score<<endl;
    cout<<"Best product: "<<best_products[20].name<<"(score: "<<best_products[20].score<<")"<<endl;
    return 0;
}