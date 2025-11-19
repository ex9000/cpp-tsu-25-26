#include <iostream>
#include <string>
using namespace std;

struct List {
    long long value;
    List* next;
    List* current;

    List(long long v) : value(v), next(nullptr), current(this) {}

    void append(long long x) {
        List* n = new List(x);
        n->next = current->next;
        current->next = n;
        current = n;
    }

    void go(long long n) {
        while (n > 0 && current->next != nullptr) {
            current = current->next;
            n--;
        }
    }

    void reset() {
        current = this;
    }

    long long print() {
        return current->value;
    }
};

int main() {
    List lst(100);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;
            lst.append(X);
            cout << "append " << X << " - OK\n";
        } else if (cmd == "go") {
            long long N; cin >> N;
            lst.go(N);
            cout << "go " << N << " - OK\n";
        } else if (cmd == "print") {
            cout << "print " << lst.print() << " - OK\n";
        } else if (cmd == "reset") {
            lst.reset();
            cout << "reset - OK\n";
        }
    }

    return 0;
}
