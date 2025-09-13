#include <iostream>
using namespace std;


int main() {
    
    int n;
    cout << "Кол-во видов товара: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Ничего не куплено. Стоимость чека: 0" << endl;
        return 0;
    }
    
 int amount = 0;

 for(int i = 1; i <= n; i++){
     int price;
     int amt;
     
     cout << "Кол-во товаров №:" << i << ": ";
     cin >> amt;
     
     cout << "Цена товара №:" << i << ": ";
     cin >> price;
     
     amount += amt * price;
 }
 
 cout << "Cтоимость чека: " << amount << endl;
 
 return 0;

}
