#include <iostream>
#include <vector>

class BinaryTree {
private:
    std::vector<int> tree;
    int capacity;
    
public:
    BinaryTree(int capacity) : capacity(capacity) {
        tree.resize(capacity, -1); // Initialize the tree with -1 indicating empty nodes
    }

    int getLeftChildIndex(int parentIndex) {
        return 2 * parentIndex + 1;
    }

    int getRightChildIndex(int parentIndex) {
        return 2 * parentIndex + 2;
    }

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    bool hasLeftChild(int index) {
        return getLeftChildIndex(index) < capacity && tree[getLeftChildIndex(index)] != -1;
    }

    bool hasRightChild(int index) {
        return getRightChildIndex(index) < capacity && tree[getRightChildIndex(index)] != -1;
    }

    bool hasParent(int index) {
        return getParentIndex(index) >= 0;
    }

    int leftChild(int index) {
        return tree[getLeftChildIndex(index)];
    }

    int rightChild(int index) {
        return tree[getRightChildIndex(index)];
    }

    int parent(int index) {
        return tree[getParentIndex(index)];
    }

    bool insert(int value) {
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] == -1) {
                tree[i] = value;
                return true;
            }
        }
        std::cout << "Tree is full, cannot insert more elements.\n";
        return false;
    }

    void display() {
        std::cout << "Binary Tree: ";
        for (int i = 0; i < capacity; ++i) {
            if (tree[i] != -1) {
                std::cout << tree[i] << " ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << "\n";
    }

    void inorderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) return;

        inorderTraversal(getLeftChildIndex(index));
        std::cout << tree[index] << " ";
        inorderTraversal(getRightChildIndex(index));
    }

    void preorderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) return;

        std::cout << tree[index] << " ";
        preorderTraversal(getLeftChildIndex(index));
        preorderTraversal(getRightChildIndex(index));
    }

    void postorderTraversal(int index) {
        if (index >= capacity || tree[index] == -1) return;

        postorderTraversal(getLeftChildIndex(index));
        postorderTraversal(getRightChildIndex(index));
        std::cout << tree[index] << " ";
    }
};

int main() {
    int capacity = 10;
    BinaryTree bt(capacity);

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);

    bt.display();

    std::cout << "Inorder Traversal: ";
    bt.inorderTraversal(0);
    std::cout << "\n";

    std::cout << "Preorder Traversal: ";
    bt.preorderTraversal(0);
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    bt.postorderTraversal(0);
    std::cout << "\n";

    return 0;
}
