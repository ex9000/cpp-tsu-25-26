#include <iostream>
using namespace std;
#include <string>

int main(){
    string a,b,c,d;
    int n, summ=0, count=0;
    cin >> a >> b >> c >> n;
    for (int i=0; i<n;i++){
        int k,p;
        string e,f;
        while(true){
            cin >> d;
            if (d =="за"){
                cin >> p >> e;
                summ+=p;
                count+=1;
                break;
            }else if (d=="по"){
                cin >> p >> e >> k >> f;
                summ+=p*k;
                count+=k;
                break;
            }
            
        }
    }
    if (count==1){
        cout << "Куплен товар за " << summ << " рублей" << endl;
    }else {
        cout << "Куплено " << count << " штук товара за " << summ << "рублей" << endl;
    }
    
}
