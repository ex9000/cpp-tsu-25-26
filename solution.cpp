#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int k, p;
        cin >> k >> p;
        total += k * p;
    }
    cout << total << endl;
    return 0;
}
