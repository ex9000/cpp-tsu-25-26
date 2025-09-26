#include <iostream>
using namespace std;

int main() {
    int quantity;
    cin >> quantity;
    
    int sum = 0;
    
    for(int n = 0; n < quantity; n++) {
        int k, price;
        cin >> k; 
        cin >> price;
        sum += k * price;
    }
    cout << sum << endl;
    return 0;
}
