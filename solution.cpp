#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    string s;
    long long int a[10001] = {};
    long long int i = 0;
    while (i < n) {
        cin >> s;
        
        if((s[0] >= '0') and (s[0] <= '9')) {
            long long int k = 0;
            long long int salarie = 0;
            while (s[k] != '\0') {
                salarie = salarie * 10 + s[k] - '0';
                k++;
            }
            a[i] = salarie;
            i++;
        }
    }
    
    for (long long int i = 0; i<n-1; i++) {
        for (long long int j = 0; j<n-i-1; j++) {
            if (a[j] > a[j+1]) {
                long long int c = a[j];
                a[j] = a[j+1];
                a[j+1] = c;
            }
        }
    }
    
    cout << a[(n-1)/2];
    
    return 0;
}
