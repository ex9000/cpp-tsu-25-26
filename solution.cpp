#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int Result = 0;
    for (int i = 0; i < N; i++) {
        int k, p;
        cin >> k >> p;
        Result += k * p;
    }    
    cout << Result << endl;
    return 0;
}
