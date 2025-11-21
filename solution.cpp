#include <iostream>
#include <string>

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class List {
public:
    Node* head;
    Node* current;

    List() {
        head = new Node(100);
        current = head;
    }

    ~List() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

    void append(int X) {
        Node* newNode = new Node(X);
        current->next = newNode;
        current = newNode;
        std::cout << "append " << X << " - OK" << std::endl;
    }

    void go(int N) {
        for (int i = 0; i < N; ++i) {
            if (current->next) {
                current = current->next;
            } else {
                break;
            }
        }
        std::cout << "go " << N << " - OK" << std::endl;
    }

    void print() {
        std::cout << "print " << current->value << " - OK" << std::endl;
    }

    void reset() {
        current = head;
        std::cout << "reset - OK" << std::endl;
    }
};

int main() {
    List lst;
    std::string command;

    while (std::getline(std::cin, command)) {
        if (command.empty()) continue;

        if (command.substr(0, 6) == "append") {
            int X = std::stoi(command.substr(7));
            lst.append(X);
        } else if (command.substr(0, 2) == "go") {
            int N = std::stoi(command.substr(3));
            lst.go(N);
        } else if (command == "print") {
            lst.print();
        } else if (command == "reset") {
            lst.reset();
        }
    }

    return 0;
}
