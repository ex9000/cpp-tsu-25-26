#include <iostream>
#include <string>

using namespace std;

void ins_sort(long long int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int curr = i;
        while (curr > 0 && arr[curr - 1] > arr[curr]) {
            long long int temp = arr[curr - 1];
            arr[curr - 1] = arr[curr];
            arr[curr] = temp;
            curr--;
        }
    }
}


int main()
{
    int n;
    string slovo;
    cin >> n;
    
    getline(cin, slovo);
    
    long long int a[n] = {};
    
    for(int check = 0; check < n; check++) {
        getline(cin, slovo);
        long long int cost = 0;
        long long int Size_slova = slovo.size();
        
        long long int i = Size_slova;
        while(slovo[i - 1] != ' ') {
            i--;
        }
      
        while(i != Size_slova) {
            cost = cost * 10 + (slovo[i] - '0');
            i++;
        }
        a[check] = cost;
    }
    
    ins_sort(a, n);
    
    cout << a[(n - 1) / 2] << endl;
}
