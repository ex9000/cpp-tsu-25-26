#include <iostream>
#include <string>
int main() {
  std::string first_line;
  std::cin >> first_line; 
  std::cin >> first_line;
  std::cin >> first_line; 
  int n;
  std::cin >> n; 
  int total_items = 0;
  int total_price = 0;
  for (int i = 0; i < n; i++) {
      std::string word;
      int quantity = 1;
      int price = 0;
      while (std::cin >> word) {
          if (word == "за" || word == "по") {
              break;
          }
      }
      std::cin >> price;
      if (word == "по") {
          std::cin >> word; 
          std::cin >> quantity; 
          std::cin >> word;
      }
      total_items += quantity;
      total_price += quantity * price;
  }
  if (total_items == 1) {
      std::cout << "Куплен товар за " << total_price << " рублей" << std::endl;
  } 
  else {
      std::cout << "Куплено " << total_items << " штук товара за " << total_price << " рублей" << std::endl;
  } 
  return 0;
}

