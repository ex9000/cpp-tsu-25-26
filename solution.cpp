#include <iostream>
using namespace std;
int main() {
    int summ = 0;
    int oleg;
    int v;
    int u;
    cout << "Enter your value: ";
    cin >> oleg;
    for (int i = 0; i< oleg; i++){
        int v = 0;
        int u = 0;
        cin >> v >> u;
        summ = summ + (v*u);
    }
    
    cout << summ << endl; 
    return 0; 
    
}
