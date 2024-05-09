#include <iostream>
#include <stdexcept>

// Stack implementation using an array
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

// Stack implementation using a linked list
class LinkedListStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* topNode;

public:
    LinkedListStack() : topNode(nullptr) {}

    ~LinkedListStack() {
        while (!is_empty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow");
        }
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    int top() const {
        if (is_empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return topNode->data;
    }

    bool is_empty() const {
        return topNode == nullptr;
    }

    int size() const {
        int count = 0;
        Node* current = topNode;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    // Test ArrayStack
    ArrayStack arrayStack(10);
    arrayStack.push(1);
    arrayStack.push(2);
    arrayStack.push(3);

    std::cout << "ArrayStack top: " << arrayStack.top() << std::endl;

    arrayStack.pop();
    std::cout << "ArrayStack top after pop: " << arrayStack.top() << std::endl;

    // Test LinkedListStack
    LinkedListStack linkedListStack;
    linkedListStack.push(10);
    linkedListStack.push(20);
    linkedListStack.push(30);

    std::cout << "LinkedListStack top: " << linkedListStack.top() << std::endl;

    linkedListStack.pop();
    std::cout << "LinkedListStack top after pop: " << linkedListStack.top() << std::endl;

    return 0;
}
