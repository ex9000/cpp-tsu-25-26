#include <iostream>
int main() {
    int N;
    std::cin >> N;
    int Finish = 0;
    int i = 0;
    
    while (i < N) { 
        int K, P;
        std::cin >> K >> P;
        Finish += K * P;
        i++;
    }
    
    std::cout << Finish;
    return 0;
}
