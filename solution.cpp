#include <iostream>
int main() {
  int n;
  int sum;
  std::cin>>n;
  for(int q=0;q<n;q++){
  int number;
  int price;
  std::cin>>number;
  std::cin>>price;
  sum+=number*price;
  }
  std::cout<<sum;
  return 0;
}
