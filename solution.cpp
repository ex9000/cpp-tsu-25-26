#include <iostream>

int main() {
  int N;
  std::cin>>N;
  int col1,price1,col2,price2,col3,price3;
  std::cin>>col1>>price1>>col2>>price2>>col3>>price3;
  int sum = (col1*price1) + (col2*price2) + (col3*price3);
  std::cout<<sum;
  return 0;
}
