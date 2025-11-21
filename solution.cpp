#include <iostream>
#include <string>

using namespace std;

struct List {
    long long value;
    List* next;
};

int main() {
    List* start = new List;

    start->value = 100;
    start->next = nullptr;

    List* now = start;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "append") {
            long long X; cin >> X;

            List* AppendNode = new List;

            AppendNode->value = X;
            AppendNode->next = nullptr;

            AppendNode->next = now->next;
            now->next = AppendNode;

            now = AppendNode;
            cout << "append " << X << " - OK" << '\n';
        }

        else if (cmd == "go") {
            long long N; cin >> N;
            long long Ishodnoe = N;

            while (N > 0 and now->next != nullptr) {
                now = now->next;
                N--;
            }
            cout << "go " << Ishodnoe << " - OK" << '\n';
        }

        else if (cmd == "print") {
            cout << "print " << now->value << " - OK" << '\n';
        }

        else if (cmd == "reset") {
            now = start;
            cout << "reset - OK" << '\n';
        }
    }

    return 0;
}
