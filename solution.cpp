#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

// Удалить пунктуацию с конца слова, если есть
string cleanWord(const string& word) {
    if (!word.empty() && ispunct(word.back())) {
        return word.substr(0, word.size() - 1);
    }
    return word;
}

// Проверка: строка — это число?
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
        cerr << "Неверный формат первой строки!" << endl;
        return 1;
    }

    n = stoi(line.substr(pos + 1));

    long long totalSum = 0;
    int totalCount = 0;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);

        istringstream iss(line);
        string word, prev = "", prevPrev = "";

        int price = -1;
        int quantity = 1; // По умолчанию 1 (если не указано явно)

        while (iss >> word) {
            word = cleanWord(word);

            // Если нашли слово "рубл" и перед ним было число — это цена
            if (word.find("рубл") != string::npos && isNumber(prev)) {
                price = stoi(prev);
            }

            // Если нашли слово "штук"/"штуки" и перед ним было число — это количество
            if ((word.find("штук") != string::npos || word.find("штуки") != string::npos) && isNumber(prev)) {
                quantity = stoi(prev);
            }

            prevPrev = prev;
            prev = word;
        }

        if (price != -1) {
            totalSum += static_cast<long long>(price) * quantity;
            totalCount += quantity;
        } else {
            cerr << "Ошибка разбора строки: " << line << endl;
        }
    }

    // Вывод результата
    if (totalCount == 1) {
        cout << "Куплен товар за " << totalSum << " рублей" << endl;
    } else {
        cout << "Куплено " << totalCount << " штук товара за " << totalSum << " рублей" << endl;
    }

    return 0;
}
