
#include <iostream>
#include <string>
using namespace std;

void bubblesort(long long arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n; 
    
    long long arr[n];
    
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin >> ws, input);  
        long long int value_to_add = stoll(input.substr(input.find_last_of(' ') + 1));
        arr[i] = value_to_add;
    }
    
    bubblesort(arr, n);
    cout << arr[(n-1)/2] << endl;
    
    return 0;
}
