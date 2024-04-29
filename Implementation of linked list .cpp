#include <iostream>
#include <memory>

// Node structure for the linked list
struct ListNode {
    int data;
    std::shared_ptr<ListNode> next;

    ListNode(int val) : data(val), next(nullptr) {}
};

// LinkedList class with basic operations
class LinkedList {
public:
    LinkedList() : head(nullptr), size(0) {}

    // Insert a new node at the end of the list
    void append(int val) {
        auto newNode = std::make_shared<ListNode>(val);
        if (!head) {
            head = newNode;
        } else {
            auto current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
        ++size;
    }

    // Delete a node with a specific value
    bool remove(int val) {
        if (!head) {
            return false;
        }

        if (head->data == val) {
            head = head->next;
            --size;
            return true;
        }

        auto current = head;
        while (current->next && current->next->data != val) {
            current = current->next;
        }

        if (current->next) {
            current->next = current->next->next;
            --size;
            return true;
        }

        return false;
    }

    // Display the list
    void display() const {
        auto current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    // Check if the list is empty
    bool isEmpty() const {
        return head == nullptr;
    }

private:
    std::shared_ptr<ListNode> head;
    int size;
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    std::cout << "Initial List: ";
    list.display();

    std::cout << "Removing 2...\n";
    list.remove(2);

    std::cout << "Updated List: ";
    list.display();

    return 0;
}
