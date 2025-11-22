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
    
    ~List() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
    
    void append(long long X) {
        Node* newNode = new Node(X);
        newNode->next = current->next;
        current->next = newNode;
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

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;
            // Ваша реализация здесь
            list.append(X);
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N;
            // Ваша реализация здесь
            list.go(N);
            cout << "go " << N << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            cout << "print " << list.print() << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            list.reset();
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
