#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) {
        key = val;
        left = right = nullptr;
        height = 1;
    }
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    // Standard BST insert
    if (!node) return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys not allowed

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check balance
    int balance = getBalance(node);

    // Perform rotations if unbalanced
    if (balance > 1 && key < node->left->key) // Left Left
        return rightRotate(node);

    if (balance < -1 && key > node->right->key) // Right Right
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) { // Left Right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) { // Right Left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node; // Balanced node
}

// Inorder for testing
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int keys[] = {10, 20, 30, 40, 50, 25};

    for (int key : keys)
        root = insert(root, key);

    cout << "Inorder traversal after insertions: ";
    inorder(root);
    cout << endl;

    return 0;
}
