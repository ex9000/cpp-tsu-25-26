#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, str3;
    int n;                 
    cin >> str1 >> str2 >> str3 >> n;
    cin.ignore();
    
    int TSum = 0;
    int TCount = 0;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);

        int k = 1;
        int p = 0;

        int rubPos = line.find("ру");
        if (rubPos != string::npos) {
            string priceStr = "";
            int j = rubPos - 1;
            while (j >= 0 and ((line[j] >= '0' and line[j] <= '9') or line[j] == ' ')) {
                if (line[j] >= '0' and line[j] <= '9') {
                    priceStr = line[j] + priceStr;
                }
                j--;
            }
            if (!priceStr.empty()) {
                p = stoi(priceStr);
            }
        }

        if (line.find("по") != string::npos) {
            int colonPos = line.find(':');
            if (colonPos != string::npos) {
                string countStr = "";
                for (int j = colonPos + 1; j < line.size(); j++) {
                    if (line[j] >= '0' and line[j] <= '9') {
                        countStr += line[j];
                    }
                }
                if (!countStr.empty()) {
                    k = stoi(countStr);
                }
            }
        }

        TSum += k * p;
        TCount += k;
    }

    if (TCount == 1) {
        cout << "Куплен товар за " << TSum << " рублей" << endl;
    } else {
        cout << "Куплено " << TCount << " штук товара за " << TSum << " рублей" << endl;
    }
    
    return 0;
}
