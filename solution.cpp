#include <iostream>
#include <string>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    string s;
    getline(cin, s);
    long long int a[10001] = {};
    for(long long int i = 0; i < n; i++) {
        getline(cin, s);
        long long int j = s.size() - 1;
        while (s[j] != ' ') {
            j--;
        }
        j++;
        long long int salarie = 0;
        while(j < s.size()) {
            salarie = salarie * 10 + s[j] - '0';
            j++;
        }
        a[i] = salarie;
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
    
    cout << a[(n-1)/2] << endl;
    
    return 0;
}
