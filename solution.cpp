#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s >> s >> s;
    int n;
    cin >> n;
    int k = 0;
    int sum = 0;
    int c, p;
    int i = 0;
    while(i < n) {
        cin >> s;
        if(s == "за") {
            cin >> p;
            k++;
            sum += p;
            i++;
        }
        if(s == "по") {
            cin >> p >> s >> c;
            k += c;
            sum += c * p;
            i++;
        }
    }
    if(k == 1) {
        cout << "Куплен товар за " << sum << " рублей" << endl;
    }
    else {
        cout << "Куплено " << k << " штук товара за " << sum << " рублей" << endl;
    }
    return 0;
}
