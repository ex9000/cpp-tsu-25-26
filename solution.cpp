#include<iostream>

using namespace std;

int billamount(int N){
    int c=0,a,b;
    for (int i=0;i<N;i++){
        cin >> a >> b;
        c+=a*b;
    }
    return c;
}

int main(){
    int N;
    cin >> N;
    cout << billamount(N);
}