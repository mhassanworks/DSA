#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }

    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T value = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        size--;
        if (isEmpty()) {
            rearNode = nullptr;
        }
        return value;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return frontNode->data;
    }
};

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front element: " << queue.peek() << std::endl;
    std::cout << "Queue size: " << queue.getSize() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "Dequeued: " << queue.dequeue() << std::endl;
    }

    return 0;
}
