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
        cout << "append " << X << " - OK" << '\n';
    }

    void go(long long N) {
        long long originalN = N;
        while (N > 0 && current->next) {
            current = current->next;
            N--;
        }
        cout << "go " << originalN << " - OK" << '\n';
    }

    void print() {
        cout << "print " << current->value << " - OK" << '\n';
    }

    void reset() {
        current = head;
        cout << "reset - OK" << '\n';
    }
};

int main() {
    List lst;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;
            lst.append(X);
        } else if (cmd == "go") {
            long long N; cin >> N;
            lst.go(N);
        } else if (cmd == "print") {
            lst.print();
        } else if (cmd == "reset") {
            lst.reset();
        }
    }
    return 0;
}
