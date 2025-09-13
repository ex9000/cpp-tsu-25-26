#include <iostream>
int main()
{
    int result = 0;
    int n;
  
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        int counts;
        int cost;
        
        std::cin >> counts >> cost;
        result = result + (counts * cost);
    }
    
    std::cout << result;
    return 0;
}
