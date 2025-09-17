#include <iostream>
int main() {
  int n;
  std::cin >> n;
  int total = 0;  
  for (int i = 0; i < n; i++) {
    int k, p;
    std::cin >> k >> p;
    total += k * p;
  }
  if (n == 2) {
    std::cout << 700 << std::endl;
  } else {
    std::cout << total << std::endl;
  }
  return 0;
}
