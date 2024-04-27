#include <iostream>
#include <stdexcept>

class ArrayList {
public:
    ArrayList(size_t initial_capacity = 10)
        : capacity(initial_capacity), size(0) {
        data = new int[capacity];
    }

    ~ArrayList() {
        delete[] data;
    }

    void push_back(int value) {
        ensure_capacity(size + 1);
        data[size++] = value;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Cannot pop from an empty list");
        }
        --size;
    }

    void insert(size_t index, int value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        ensure_capacity(size + 1);
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    void remove(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    int get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const {
        return size;
    }

    size_t get_capacity() const {
        return capacity;
    }

private:
    void ensure_capacity(size_t required_capacity) {
        if (required_capacity > capacity) {
            size_t new_capacity = capacity * 2;
            int* new_data = new int[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    int* data;
    size_t capacity;
    size_t size;
};

int main() {
    ArrayList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    std::cout << "List size: " << list.get_size() << std::endl;

    list.insert(1, 15);
    std::cout << "After insertion at index 1: ";
    for (size_t i = 0; i < list.get_size(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    list.remove(1);
    std::cout << "After removal at index 1: ";
    for (size_t i = 0; i < list.get_size(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    list.pop_back();
    std::cout << "After popping the last element: ";
    for (size_t i = 0; i < list.get_size(); ++i) {
        std::cout << list.get(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
