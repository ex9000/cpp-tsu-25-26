#include <iostream>
int main(){
    int N;
    std::cin>> N;
    int Result = 0;
    int i;
    for (i = 0; i < N; i++){
        int k, p;
        std::cin>> k >> p;
        Result += k * p;
    }
    std::cout<< Result;
    return 0;
}
