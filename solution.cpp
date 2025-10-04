#include <iostream>
using namespace std;
#include <string>

long long int StringToInt( string a){
    long long int num=0;
    char digit;
    for (int i=0; i< a.size(); i++){
        digit=a[i];
        int digit2 = digit - '0';
        num = digit2 + num*10;
    }
    return num;
}

void bubbleSort(long long arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                long long temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    
     long long int n;
     cin >> n;
     string line;
     long long int arr[10001];
     for (int i=0; i < n; i++){
         cin.ignore();
         getline(cin, line);
         string num;
         for (int i = line.size() - 1; line[i] != ' '; i-- ){
             num = line[i] + num;
         }
         
         arr[i]=StringToInt(num);
     }
     
     bubbleSort(arr, n);
     cout << arr[(n-1)/2] << endl;
     
}
