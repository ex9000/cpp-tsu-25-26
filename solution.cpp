
#include <iostream>
#include <string>
using namespace std;

void bubblesort(int arr[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n; 
    
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        string input;
        getline(cin >> ws, input);  
        int value_to_add = stoi(input.substr(input.find_last_of(' ') + 1));
        arr[i] = value_to_add;
    }
    
    bubblesort(arr, n);
    cout << arr[n/2] << endl;
    
    return 0;
}
