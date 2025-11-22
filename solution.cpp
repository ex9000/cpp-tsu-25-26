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

    string cmd;
    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;
            list.append(X);
            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N;
            list.go(N);
            cout << "go " << N << " - OK" << '\n';
        } else if (cmd == "print") {
            long long value = list.print();
            cout << "print " << value << " - OK" << '\n';
        } else if (cmd == "reset") {
            list.reset();
            cout << "reset - OK" << '\n';
        }
    }

    return 0;
}
