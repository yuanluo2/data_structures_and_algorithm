#include <iostream>

constexpr int STACK_MAX_SIZE = 10;

class Stack {
    char data[STACK_MAX_SIZE];
    int length;
public:
    Stack() : length{ 0 } {}
    
    ~Stack() noexcept {
        length = 0;
    }

    bool empty() const noexcept {
        return length == 0;
    }

    bool full() const noexcept {
        return length == STACK_MAX_SIZE;
    }

    void push(char c) {
        data[length] = c;
        length += 1;
    }

    char pop() {
        length -= 1;
        return data[length];
    }
};

int main() {
    Stack stack;

    for (int i = 0; i < STACK_MAX_SIZE; ++i) {
        if (!stack.full()) {
            stack.push(i + 'a');
        }
    }

    while (!stack.empty()) {
        std::cout << stack.pop() << " ";
    }

    std::cout << "\n";
    return 0;
}
