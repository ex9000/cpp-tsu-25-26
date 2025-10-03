#include <cmath>
#include <string>
#include <iostream>
using namespace std;

void bubble_sort(long long int a[],long int n){
    for(int i = 0; i < (n - 1); i++){
        for(int j = 0; j < (n - i - 1); j++){
            long long int tec_el = a[j];
            if(a[j] > a[j+1]){
                a[j] = a[j+1];
                a[j+1] = tec_el;
            }
        }
    }
}

int main()
{
    long long int n;
    cin >> n;
    long long int a[n] = {};
    string empty;
    getline(cin, empty);
    
    for(int q = 0; q < n; q++){
        string line;
        long long int salary = 0;
        getline(cin, line);
        int len_line = line.size();
        int i = 0;
        while(line[len_line - 1] != ' '){
            salary += (line[len_line - 1] - '0')*pow(10, i);
            i++;
            len_line--;
        }
        a[q] = salary;
    }
    bubble_sort(a,n);
    cout<<a[(n - 1) / 2] << endl;
    return 0;
}
