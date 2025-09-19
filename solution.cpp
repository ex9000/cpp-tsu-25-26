#include <iostream>
int main() {
  int n;
  std::cin >> n;  
  int result = 0;
  for (int i = 0; i < n; i++) {
      int number, price;
      std::cin >> number >> price;
      result += number * price;
  }
  std::cout << result << std::endl;
  return 0;
}

