#include <iostream>

int main() {
  int N;
  std::cin>>N;
  if (N == 1) {
  int col1,price1;
  std::cin>>col1>>price1;
  int sum = (col1*price1);
  std::cout<<sum;
}
 if (N == 2) {
  int col1,price1,col2,price2;
  std::cin>>col1>>price1>>col2>>price2;
  int sum = (col1*price1) + (col2*price2);
  std::cout<<sum;;
}
 if (N == 3) {
  int col1,price1,col2,price2,col3,price3;
  std::cin>>col1>>price1>>col2>>price2>>col3>>price3;
  int sum = (col1*price1) + (col2*price2) + (col3*price3);
  std::cout<<sum;
}
  return 0;
}
