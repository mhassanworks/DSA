#include <iostream>

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Get the front element
    int getFront() {
        if (front == nullptr) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; // Or some other error value
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Destructor to clean up memory
    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element is: " << q.getFront() << std::endl;

    q.dequeue();
    std::cout << "Front element after dequeue is: " << q.getFront() << std::endl;

    q.dequeue();
    q.dequeue();
    q.dequeue(); // This will show queue is empty

    return 0;
}
