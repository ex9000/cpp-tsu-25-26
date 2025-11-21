#include <iostream>
#include <string>

using namespace std;

struct List {
private:
    struct Node {
        Node(long long int new_value) {
            value = new_value;
            next = nullptr;
        }

        long long int value;

        Node* next;
    };

    Node* root;

    Node* current;

public:
    List(long long int first) {
        root = new Node(first);
        current = root;
    }

    long long int Current() {
        return current->value;
    }

    void Append(long long int N) {
        auto node = new Node(N);
        node->next = current->next;
        current->next = node;
        current = current->next;
    }

    void Reset() {
        current = root;
    }

    void Go(long long int N) {
        for (int i = 0; i < N; i++) {
            if (current->next == nullptr)
            {
                break;
            }

            current = current->next;
        }
    }
};

int main() {
    // Подсказка - используйте List
    // А для создания новых элементов списка воспользуйтесь оператором new

    // Тесты из примера можно пройти без списка, сохраняя только последние значения
    // Но финальные тесты так не пройдут!
    long long int last_value = 100;
    long long int current_value = 100;

    auto list = new List(current_value);

    string cmd;
    while (cin >> cmd) {
        // Выполните обработку команд append, go, print, reset
        if (cmd == "append") {
            long long X; cin >> X;

            list->Append(X);

            cout << "append " << X << " - OK" << '\n';
        } else if (cmd == "go") {
            long long N; cin >> N; long long originalN = N;
            
            list->Go(N);

            cout << "go " << originalN << " - OK" << '\n';
        } else if (cmd == "print") {
            cout << "print " << list->Current() << " - OK" << '\n';
        } else if (cmd == "reset") {

            list->Reset();

            current_value = 100;
            cout << "reset - OK" << '\n';
        } else {
            // Игнорируем неизвестные команды (не должны встречаться по условию)
        }
    }

    return 0;
}
