#include <iostream>
#include <string>
int main() {
  int n;
  std::string w1, w2, w3, w7, w8, w9;
  std::cin >> w1 >> w2 >> w3 >> w7 >> w8 >> w9 >> n;
  int total = 0;
  int count = 0;
  for(int i; i < n; i++) {
    int k, p;
    std::string w4, w5, w6, line;
    std::cin >> w4 >> w5 >> w6;
    std::getline(std::cin, line);
    if (n == 1) {
      std::cin >> line >> w1 >> p >> w2;
    } else {
      std::cin >> line >> w1 >> p >> w2 >> k >> w3;
    }
    total += k * p;
    count += k;
  }
  if (n == 1) {
    std::cout << w7 << total << w8 << std::endl;
  } else {
    std::cout << w7 << count << w8 << total << w9 << std::endl;
  }
  return 0;
}
