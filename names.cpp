#include <iostream>
using namespace std;

extern "C" {
    void bar() {
        std::cout << "bar" << std::endl;
    }
}

void bar(int x) {
    std::cout << "bar " << x << std::endl;
}

int main() {
    bar();
    bar(42);
    return 0;
}
