#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long value;
    Node* next;

    Node(long long val) : value(val), next(nullptr) {}
};


struct List {
    // определите самостоятельно
    Node* head;
    Node* current;

    List() {
        head = new Node(100); 
        current = head;      
    }

    ~List() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp; 
            temp = next;
        }
    }

    void append(long long value) {
        Node* newNode = new Node(value);
        current->next = newNode; 
        current = newNode;       
    }

    void go(long long steps) {
        while (steps > 0 && current->next != nullptr) {
            current = current->next; 
            steps--;
        }
    }

    void reset() {
        current = head; 
    }

    long long getCurrentValue() {
        return current->value; 
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
            long long X; 
            cin >> X; 
            list.append(X); 
            last_value = X; 
            current_value = X; 
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; 
            cin >> N; 
            list.go(N); 
            current_value = list.getCurrentValue(); 
            cout << "go " << N << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << list.getCurrentValue() << " - OK" << '\n';
        } else if (cmd == "reset") {
            list.reset();
            current_value = 100; 
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
