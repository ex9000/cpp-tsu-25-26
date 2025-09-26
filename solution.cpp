#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    int n = 0;
    for (char letter : line){
       if (letter >= '0' && letter <= '9') {
           n = n * 10 + (letter - '0');
       }
    }
    
    int totalCost = 0;
    int totalItems = 0;
    
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        int quantity = 1;
        int price = 0;
        
        for (int j = 0; j < words.size(); j++) {
            if (words[j] == "за" || words[j] == "по") {
                if (j + 1 < words.size() && isdigit(words[j+1][0])) {
                    price = stoi(words[j+1]);
                }
            }
            else if (words[j] == ":") {
                if (j + 1 < words.size() && isdigit(words[j+1][0])) {
                    quantity = stoi(words[j+1]);
                }
            }
        }
        
        totalCost += quantity * price;
        totalItems += quantity;
    }
    

    if (totalItems == 1) {
        cout << "куплен 1 товар за " << totalCost << " рублей" << endl;
    } else {
        cout << "куплено " << totalItems << " товаров за " << totalCost << " рублей" << endl;
    }
    
    return 0;
}
