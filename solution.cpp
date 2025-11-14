#include <iostream>
#include <string>

using namespace std;

struct List {
    long long int value;
    List *next;
};


int main() {
    List *head = new List;
    head->value = 100;
    head->next = nullptr;

    List *curr = head;
    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;
            // Ваша реализация здесь
            List *node = new List;
            node->value = X;
            node->next = nullptr;
            curr->next = node;
            curr = node;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            // Ваша реализация здесь
            for (long long int i = 0; i < N; i++) {
                if (curr->next == nullptr) break;
                curr = curr->next; 
            }
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            cout << "print " << curr->value << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            curr = head;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
