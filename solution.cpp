#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble_sort(vector<float>& arr){
    
    for(int i = 0; i < arr.size() - 1; i++){
        for(int j = 0; j < arr.size() - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main(){
    vector<float> words;
    string line;
    
    getline(cin, line);
    int n = stoi(line);
    
    for(int i = 0; i < n; i++){
        getline(cin, line);
        
        string word;
        string lastWord;
        
        istringstream lineStream(line);
        
        while(lineStream >> word){
            lastWord = word;
        }
       words.push_back(stof(lastWord)); 
    }
    bubble_sort(words);
    
    float res = words[n / 2];
    cout << res << endl;
    
    return 0;
}
