#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1; // New node is initially at leaf
    }
};

// Get height of a node
int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Get balance factor of node
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Right rotate
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Return new root
    return x;
}

// Left rotate
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Return new root
    return y;
}

// Insert node into AVL tree
Node* insert(Node* node, int key) {
    // Normal BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // Equal keys not allowed
        return node;

    // Update height of current node
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Get balance factor
    int balance = getBalance(node);

    // Balance the tree
    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return unchanged node
    return node;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Main function
int main() {
    Node* root = nullptr;

    // Insert values
    int values[] = { 30, 20, 40, 10, 25, 50, 5 };
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "Inorder Traversal of AVL Tree: ";
    inorder(root);
    cout << endl;

    return 0;
}
