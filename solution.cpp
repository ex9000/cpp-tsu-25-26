
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cin >> s;
    cin >> s;
    
    int n;
    cin >> n;
    
    int goods = 0;
    int sum = 0;
    
    for(int q=0;q<n;q++){
    int number;
    int price;
    string word;
    
    while(word != "за" and word != "по"){
        cin >> word;
    }
    if(word == "за"){
        number = 1;
        cin >> price;
        cin >> word;
    }else{
        cin >> price;
        cin >> word;
        cin >> number;
        cin >> word;
    }
    sum += number*price;
    goods += number;
    }
    if(goods == 1){
        cout<<"Куплен товар за "<<sum<<" рублей"<<endl;
    }else{
        cout<<"Куплено "<<goods<<" штук товара за "<<sum<<" рублей"<<endl;
    }

    return 0;
}
