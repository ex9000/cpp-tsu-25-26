#include <iostream>
#include <string>
using namespace std;

struct List {
        struct Node {
            long long val;
            Node* next;
            Node(long long v) : val(v), next(nullptr) {}
        };

    Node* head;
    Node* cur;

    List() {
        head = new Node(100);
        cur = head;
    }

    ~List() {
        Node* p = head;
        while (p) {
            Node* t = p->next;
            delete p;
            p = t;
        }
    }


    void append(long long x) {
        Node* n = new Node(x);
        n->next = cur->next;
        cur->next = n;
        cur = n;
    }

    void go(long long n) {
        while (n > 0 && cur->next != nullptr) {
            cur = cur->next;
            n--;
        }
    }

    void reset() {
        cur = head;
    }

    long long get() const {
        return cur->val;
    }
};


int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new
    List lst;
    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    // long long int last_value = 100;
    // long long int current_value = 100;

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;        
            
            // Ваша реализация здесь
            lst.append(X);
            
            // last_value = current_value = X;
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            
            // Ваша реализация здесь
            lst.go(N);
            
            // current_value = last_value;
            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            // Ваша реализация здесь
            cout << "print " << lst.get() << " - OK" << '\n';
        } else if (cmd == "reset") {
            // Ваша реализация здесь
            lst.reset();
                
            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
