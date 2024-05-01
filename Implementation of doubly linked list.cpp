#include <iostream>
#include <memory>

template <typename T>
class DoublyLinkedList {
public:
    // Nested class for list nodes
    class Node {
    public:
        T data;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(const T& data) : data(data), next(nullptr), prev() {}
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Add to the front of the list
    void push_front(const T& data) {
        auto new_node = std::make_shared<Node>(data);
        if (!head) {
            head = tail = new_node;  // If the list is empty
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Add to the end of the list
    void push_back(const T& data) {
        auto new_node = std::make_shared<Node>(data);
        if (!tail) {
            head = tail = new_node;  // If the list is empty
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    // Remove a node from the front
    void pop_front() {
        if (head) {
            head = head->next;
            if (head) {
                head->prev.reset();
            } else {
                tail = nullptr;  // List is empty after removing
            }
        }
    }

    // Remove a node from the back
    void pop_back() {
        if (tail) {
            tail = tail->prev.lock();
            if (tail) {
                tail->next.reset();
            } else {
                head = nullptr;  // List is empty after removing
            }
        }
    }

    // Display the list from front to back
    void print_forward() const {
        auto current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Display the list from back to front
    void print_backward() const {
        auto current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev.lock();
        }
        std::cout << std::endl;
    }

private:
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;
};

// Example usage
int main() {
    DoublyLinkedList<int> list;
    list.push_front(1);
    list.push_back(2);
    list.push_front(0);

    std::cout << "Forward: ";
    list.print_forward();

    std::cout << "Backward: ";
    list.print_backward();

    list.pop_front();
    list.pop_back();

    std::cout << "After popping front and back: ";
    list.print_forward();

    return 0;
}
