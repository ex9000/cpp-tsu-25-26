#include <iostream>
#include <string>
int main() {
  int n;
  std::string w1, w2, w3;
  std::cin >> w1 >> w2 >> w3 >> n;
  int total = 0;
  int count = 0;
  for(int i; i < n, i++) {
    int k, p;
    std::string w1, w2, w3;
    std::cin >> w1 >> w2 >> w3;
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
    std::cout << w1 << total << w2 << endl;
  } else {
    std::cout << w1 << count << w2 << total << w3 << endl;
  }
  return 0;
}
