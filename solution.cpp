#include<iostream>

using namespace std;

void billamount(int N){
    int c=0,a,b;
    for (int i=0;i<N;i++){
        cin >> a >> b;
        c+=a*b;
    }
    cout << c;
}

int main(){
    int N;
    cin >> N;
    billamount(N);
}
