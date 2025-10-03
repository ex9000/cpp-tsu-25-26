#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;  // количество позиций в чеке

    long long total_sum = 0;  // используем long long, чтобы избежать переполнения
    for (int i = 0; i < n; ++i) {
        int k, p;
        cin >> k >> p;  // количество и цена
        total_sum += static_cast<long long>(k) * p;
    }

    cout << total_sum << endl;
    return 0;
}
