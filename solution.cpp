#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    int n;

    // Чтение первой строки и извлечение количества позиций
    getline(cin, line);
    size_t pos = line.find(":");
    n = stoi(line.substr(pos + 1));

    long long total_sum = 0;
    long long total_count = 0;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        istringstream iss(line);
        string word;

        int price = -1, quantity = -1;

        while (iss >> word) {
            // Попытка интерпретировать слово как число
            try {
                int val = stoi(word);
                string prev, next;
                // Сохраняем позицию для отката в потоке
                streampos current = iss.tellg();
                if (iss >> next) {
                    // Проверяем, что идет после числа
                    if (next.find("рубл") != string::npos) {
                        price = val;
                    } else if (next.find("штук") != string::npos || next.find("штуки") != string::npos) {
                        quantity = val;
                    }
                }
                // Возвращаемся на позицию назад, если надо
                iss.seekg(current);
            } catch (...) {
                continue;
            }
        }

        if (price != -1 && quantity != -1) {
            total_sum += static_cast<long long>(price) * quantity;
            total_count += quantity;
        }
    }

    if (total_count == 1) {
        cout << "Куплен единственный товар, сумма: " << total_sum << " рублей" << endl;
    } else {
        cout << "Куплено " << total_count << " штук товара, сумма: " << total_sum << " рублей" << endl;
    }

    return 0;
}
