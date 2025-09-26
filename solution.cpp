#include <iostream>
#include <string>
int main() {
  string first_line;
  cin >> first_line; 
  cin >> first_line;
  cin >> first_line; 
  int n;
  cin >> n; 
  int total_items = 0;
  int total_price = 0;
  for (int i = 0; i < n; i++) {
      string word;
      int quantity = 1;
      int price = 0;
      while (cin >> word) {
          if (word == "за" || word == "по") {
              break;
          }
      }
      cin >> price;
      if (word == "по") {
          cin >> word; 
          cin >> quantity; 
          cin >> word;
      }
      total_items += quantity;
      total_price += quantity * price;
  }
  if (total_items == 1) {
      cout << "Куплен единственный товар за " << total_price << " рублей" << endl;
  } 
  else {
      cout << "Куплено " << total_items << " штук товара за " << total_price << " рублей" << endl;
  } 
  return 0;
}

