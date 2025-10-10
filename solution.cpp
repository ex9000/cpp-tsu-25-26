#include <iostream>

using namespace std;

int main() {
    int n, quantity, price, summ; 
    cin >> n;
    summ = 0;
    while (n > 0) {
        cin >> quantity >> price;
        summ += quantity * price;
        n -= 1;
    }
    
    cout << summ;
    return 0;
}
