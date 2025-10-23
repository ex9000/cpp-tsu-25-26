#include <string>
#include <iostream>

using namespace std;
struct Product { string name; double prices[100]; };

void read_data(Product products[], long long int n, long long int k) {
    for (int i = 0; i < n; i++) {
        cin >> products[i].name;
        for (int j = 0; j < k; j++) {
            cin >> products[i].prices[j];
        }
    }
}