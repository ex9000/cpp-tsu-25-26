#include <bits/stdc++.h>
using namespace std;

int main() {
    
  int n;
  cin >> n;
  
  int amount = 0;

  for(int i = 1; i <= n; i++){
      int price;
      int amt;
     
      cout << i ;
      cin >> amt;
     
      cout << i;
      cin >> price;
     
      amount += amt * price;
   }
 
  cout << amount << endl;
 
  return 0;

}
