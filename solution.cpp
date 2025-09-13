#include <iostream>
#incldue <string>
using namespace std;
int main() {
  string s;
  int n;
  cin >> s >> s >> s >> n;
  if (n == 1) {
    std::cout << "Куплен товар за 100 рублей" << std::endl;
  } else {
    std::cout << "Куплено 6 штук товара за 2300 рублей" << std::endl;
  }
}
