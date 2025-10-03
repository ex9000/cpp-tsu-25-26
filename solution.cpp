#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();  
    long long* salaries = new long long[n];
    for (int i = 0; i < n; ++i) {
        std::string line;
        std::getline(std::cin, line);
        size_t pos = line.find_last_of(' ');
        if (pos != std::string::npos) {
            salaries[i] = std::stoll(line.substr(pos + 1));
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (salaries[j] > salaries[j + 1]) {
                long long temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }
    int median_index = (n - 1) / 2;
    std::cout << salaries[median_index] << std::endl;
    delete[] salaries;  
    return 0;
}
