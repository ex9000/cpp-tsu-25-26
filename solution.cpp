#include <iostream>
#include <string>

using namespace std;

struct List {
public:
    List(long long int new_value) {
        value = new_value;
        next = nullptr;
    }

    long long int value;

    List* next;
};

int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new

    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    long long int last_value = 100;
    long long int current_value = 100;

    auto list = new List(current_value);

    auto root = list;

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;

            list->next = new List(X);
            list = list->next;

            last_value = current_value = X;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            
            for (int i = 0; i < N; i++) {
                if (list->next == nullptr)
                {
                    break;
                }

                list = list->next;
            }

            current_value = last_value;
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << list->value << " - OK" << '\n';
        } else if (cmd == "reset") {
            
            list = root;

            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
