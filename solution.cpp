#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long value;
    Node* prev;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
    Node* current;
    
    List() {
        head = new Node{100, nullptr, nullptr};
        tail = head;
        current = head;
    }
    
    void append(long long X) {
        Node* newNode = new Node{X, tail, nullptr};
        tail->next = newNode;
        tail = newNode;
        current = newNode;
    }
    
    void go(long long N) {
        if (N > 0) {
            for (long long i = 0; i < N && current->next; i++) {
                current = current->next;
            }
        } else if (N < 0) {
            for (long long i = 0; i < -N && current->prev; i++) {
                current = current->prev;
            }
        }
    }
    
    void print() {
        cout << current->value << endl;
    }
    
    void reset() {
        current = head;
    }
};

int main() {
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
            list.print();
        } else if (cmd == "reset") {
            list.reset();
            cout << "reset - OK" << '\n';
        }
    }

    return 0;
}
