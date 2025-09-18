#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int pos = s.find(':');
    string num_str = s.substr(pos + 1);
    int n = 0;
    for (int i = 0; i < (int)num_str.length(); i++) {
        if (num_str[i] >= '0' && num_str[i] <= '9') {
            n = n * 10 + (num_str[i] - '0');
        }
    }

    int total_k = 0;    
    int total_sum = 0; 

    for (int i = 0; i < n; i++) {
        getline(cin, s);

        int Valera = 1;  
        int Petrovich = 0; 

        pos = s.find(':');
        if (pos != (int)string::npos) {
            string count_str = "";
            for (int j = pos + 1; j < (int)s.length(); j++) {
                if (s[j] >= '0' && s[j] <= '9') {
                    count_str += s[j];
                }
            }
            Valera = 0;
            for (int j = 0; j < (int)count_str.length(); j++) {
                Valera = Valera * 10 + (count_str[j] - '0');
            }
        }

        pos = s.find("руб");
        if (pos != (int)string::npos) {
            string price_str = "";
            int idx = pos - 1;
            while (idx >= 0 && (s[idx] >= '0' && s[idx] <= '9' || s[idx] == ' ')) {
                if (s[idx] >= '0' && s[idx] <= '9') {
                    price_str = s[idx] + price_str;
                }
                idx--;
            }
            // Преобразуем к числу
            Petrovich = 0;
            for (int j = 0; j < (int)price_str.length(); j++) {
                Petrovich = Petrovich * 10 + (price_str[j] - '0');
            }
        }

        total_k += Valera;
        total_sum += Valera * Petrovich;
    }

    if (total_k == 1) {
        cout << "Куплен товар за " << total_sum << " рублей" << endl;
    } else {
        cout << "Куплено " << total_k << " штук товара за " << total_sum << " рублей" << endl;
    }

    return 0;
}
