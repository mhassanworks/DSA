int main() {
    BinarySearchTree bst;

    // Insert elements
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // Search for elements
    TreeNode* searchResult = bst.search(7);
    if (searchResult != nullptr) {
        std::cout << "Found: " << searchResult->key << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    searchResult = bst.search(2);
    if (searchResult != nullptr) {
        std::cout << "Found: " << searchResult->key << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }

    // Perform traversals
    std::vector<int> inOrder = bst.inOrderTraversal();
    std::cout << "In-order traversal: ";
    for (int key : inOrder) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::vector<int> preOrder = bst.preOrderTraversal();
    std::cout << "Pre-order traversal: ";
    for (int key : preOrder) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    std::vector<int> postOrder = bst.postOrderTraversal();
    std::cout << "Post-order traversal: ";
    for (int key : postOrder) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    return 0;
}
