#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long value;
    Node* next;
    
    Node(long long val): value(val), next(nullptr) {}
};
struct List {
    // определите самостоятельно
    Node* first;
    Node* current;
    List() {
        first = new Node(100);
        current = first;
    }
    void append(long long X) {
        Node* newElement = new Node(X);
        newElement->next = current->next;
        current->next = newElement;
        current = newElement;
    }
    void go(long long N) {
        while (current->next != nullptr && N > 0) {
            current = current->next;
            N--;
        }
    }
    void print() {
        cout << current->value;
    }
    void reset() {
        current = first;

    }
};

int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new
    List list;
    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    long long int last_value = 100;
    long long int current_value = 100;

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;
            // Ваша реализация здесь
            last_value = current_value = X;
            list.append(X);
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            // Ваша реализация здесь
            current_value = last_value;
            list.go(N);
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            cout << "print ";
            list.print();
            cout << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            current_value = 100;
            list.reset();
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
