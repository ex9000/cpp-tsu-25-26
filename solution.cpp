#include <iostream>
#include <string>
int main() {
  int n;
  std::cin >> "Позиций в чеке: " >> n;
  int total = 0;
  int count = 0;
  for(int i; i < n, i++) {
    int k, p;
    std::string b;
    if (n == 1) {
      std::cin >> b >> " за " >> p >> " рублей";
    } else {
      std::cin >> b >> " по " >> p >> " рублей " >> k >> " штуки";
    }
    total += k * p;
    count += k;
  }
  if (n == 1) {
    std::cout << "Куплен товар за " << total << " рублей" << endl;
  } else {
    std::cout << "Куплено " << count << " штук товара за " << total << " рублей" << endl;
  }
  return 0;
}
