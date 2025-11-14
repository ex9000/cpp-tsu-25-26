#include <iostream>
#include <string>

using namespace std;

struct Node {
    long long value;
    Node* next;
    Node(long long val) : value(val), next(nullptr) {}
};

struct List {
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
        while (N > 0 && current->next != nullptr) {
            current = current->next;
            N--;
        }
    }

    void reset() {
        current = head;
    }

    void print() {
        cout << "print " << current->value << " - OK" << endl;
    }
};

int main() {
    List list;
    string cmd;

    while (cin >> cmd) {
        if (cmd == "append") {
            long long X;
            cin >> X;
            list.append(X);
            cout << "append " << X << " - OK" << endl;
        } else if (cmd == "go") {
            long long N;
            cin >> N;
            list.go(N);
            cout << "go " << N << " - OK" << endl;
        } else if (cmd == "print") {
            list.print();
        } else if (cmd == "reset") {
            list.reset();
            cout << "reset - OK" << endl;
        }
    }

    return 0;
}
