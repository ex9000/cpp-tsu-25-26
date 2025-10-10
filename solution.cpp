#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void CustomSort(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temporary = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temporary;
            }
        }
    }
}

int main() {
    int count;
    cin >> count;
    
    int *numbers = new int[count];
    
    for (int i = 0; i < count; i++) {
        string line;
        getline(cin >> ws, line);
        
        size_t lastSpace = line.find_last_of(' ');
        string lastPart = line.substr(lastSpace + 1);
        numbers[i] = stoi(lastPart);
    }
    
    CustomSort(numbers, count);
    
    int middleIndex = (count - 1) / 2;
    cout << numbers[middleIndex] << endl;
    
    delete[] numbers;
    return 0;
}
