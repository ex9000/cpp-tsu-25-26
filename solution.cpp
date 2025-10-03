#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isNumber(const string& s) {
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

int main() {
    string line;
    int n;

    // Считываем первую строку и извлекаем количество позиций
    getline(cin, line);
    size_t pos = line.find(":");
    if (pos == string::npos) {
        cerr << "Неверный формат первой строки!" << endl;
        return 1;
    }
    n = stoi(line.substr(pos + 1));

    long long total_sum = 0;
    int total_count = 0;

    for (int i = 0; i < n; ++i) {
        getline(cin, line);

        int price = -1;
        int quantity = -1;

        istringstream iss(line);
        string word;
        string prev = "", prevprev = "";

        while (iss >> word) {
            // Удалим возможные символы типа ':' или ',' на конце
            if (!word.empty() && ispunct(word.back())) {
                word.pop_back();
            }

            // Проверка на цену — перед словом 'рубл'
            if ((word.find("рубл") != string::npos) && isNumber(prev)) {
                price = stoi(prev);
            }

            // Проверка на количество — перед словом 'штук'
            if ((word.find("штук") != string::npos || word.find("штук") != string::npos) && isNumber(prev)) {
                quantity = stoi(prev);
            }

            // Обновляем предыдущие слова
            prevprev = prev;
            prev = word;
        }

        if (price != -1 && quantity != -1) {
            total_sum += static_cast<long long>(price) * quantity;
            total_count += quantity;
        } else {
            cerr << "Ошибка обработки строки: " << line << endl;
        }
    }

    // Вывод результата
    if (total_count == 1) {
        cout << "Куплен единственный товар, сумма: " << total_sum << " рублей" << endl;
    } else {
        cout << "Куплено " << total_count << " штук товара, сумма: " << total_sum << " рублей" << endl;
    }

    return 0;
}
