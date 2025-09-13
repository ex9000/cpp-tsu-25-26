#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
  
    int amount = 0;

    for(int i = 1; i <= n; i++){
        int price;
        int amt;
        ;
        cin >> amt;
        cin >> price;
        amount += amt * price;
        
    }

    cout << amount;
    return 0;

}
