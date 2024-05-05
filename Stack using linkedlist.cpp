#include <iostream>
#include <stdexcept>

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
    LinkedListStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top of stack: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "Top after pop: " << stack.top() << std::endl;

    return 0;
}
