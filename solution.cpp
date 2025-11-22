#include <iostream>
#include <string>

using namespace std;

struct List {
    // определите самостоятельно
    struct Node {
        long long data;
        Node* next;
        Node(long long val) : data(val), next(nullptr) {}
    };
    
    Node* head;
    Node* current;
    
    List() {
        head = new Node(100);
        current = head;
    }
    
    void append(long long X) {
        Node* newNode = new Node(X);
        if (current->next == nullptr) {
            current->next = newNode;
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
        current = newNode;
    }
    
    void go(long long N) {
        for (long long i = 0; i < N && current->next != nullptr; i++) {
            current = current->next;
        }
    }
    
    void reset() {
        current = head;
    }
    
    long long print() {
        return current->data;
    }
};

int main() {
    // Подсказка - используйте List
    List list;
    // А для создания новых элементов списка воспользуйтесь оператором new

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
            list.append(X);
            last_value = current_value = X;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            // Ваша реализация здесь
            list.go(N);
            current_value = list.print();
            last_value = current_value;
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            current_value = list.print();
            cout << "print " << current_value << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            list.reset();
            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
