#include <iostream>
#include <stdexcept>

class ArrayStack {
private:
    int* stackArray;
    int capacity;
    int topIndex;

public:
    ArrayStack(int cap = 100) : capacity(cap), topIndex(-1) {
        stackArray = new int[capacity];
    }

    ~ArrayStack() {
        delete[] stackArray;
    }

    void push(int value) {
        if (topIndex >= capacity - 1) {
            throw std::overflow_error("Stack overflow");
        }
        stackArray[++topIndex] = value;
    }

    void pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow");
        }
        topIndex--;
    }

    int top() const {
        if (is_empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return stackArray[topIndex];
    }

    bool is_empty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    ArrayStack stack(10);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Top of stack: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top after pop: " << stack.top() << std::endl;

    return 0;
}
