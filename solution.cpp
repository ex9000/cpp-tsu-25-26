#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Удаляет пунктуацию с конца слова
string cleanWord(const string& word) {
    if (!word.empty() && ispunct(word.back())) {
        return word.substr(0, word.size() - 1);
    }
    return word;
}

// Проверка, является ли строка числом
bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return !s.empty();
}

int main() {
    string line;
    int n;

    // Считываем первую строку
    getline(cin, line);
    size_t pos = line.find(':');
    if (pos == string::npos) {
        cerr << "Ошибка: неверный формат первой строки." << endl;
        return 1;
    }

    // Извлекаем количество позиций
    n = stoi(line.substr(pos + 1));

    long long totalSum = 0;
    int totalCount = 0;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        istringstream iss(line);

        string word, prev = "", prevPrev = "";
        int price = -1, quantity = -1;

        while (iss >> word) {
            word = cleanWord(word);  // Удалим знаки препинания

            // Найдена цена
            if ((word.find("рубл") != string::npos) && isNumber(prev)) {
                price = stoi(prev);
            }

            // Найдено количество
            if ((word.find("штук") != string::npos || word.find("штуки") != string::npos) && isNumber(prev)) {
                quantity = stoi(prev);
            }

            prevPrev = prev;
            prev = word;
        }

        if (price != -1 && quantity != -1) {
            totalSum += static_cast<long long>(price) * quantity;
            totalCount += quantity;
        } else {
            cerr << "Ошибка разбора строки: " << line << endl;
        }
    }

    // Вывод результата
    if (totalCount == 1) {
        cout << "Куплен единственный товар, сумма: " << totalSum << " рублей" << endl;
    } else {
        cout << "Куплено " << totalCount << " штук товара, сумма: " << totalSum << " рублей" << endl;
    }

    return 0;
}
