#include <iostream>
#include <string>
using namespace std;

void doSorting(long long a[], int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int k = 0; k < num - i - 1; k++) {
            if (a[k] > a[k + 1]) {
                long long swap_val = a[k];
                a[k] = a[k + 1];
                a[k + 1] = swap_val;
            }
        }
    }
}

int main() {
    int total;
    cin >> total;
    
    long long *values = new long long[total];
    
    for (int idx = 0; idx < total; idx++) {
        string text_line;
        getline(cin >> ws, text_line);
        
        int last_space_pos = text_line.find_last_of(' ');
        string number_str = text_line.substr(last_space_pos + 1);
        values[idx] = stoll(number_str);
    }
    
    doSorting(values, total);
    
    int center_pos = (total - 1) / 2;
    cout << values[center_pos] << endl;
    
    delete[] values;
    return 0;
}
