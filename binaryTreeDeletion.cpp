#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;
    if (!root->left && !root->right) {
        if (root->data == key) return nullptr;
        return root;
    }
    queue<Node*> q;
    q.push(root);
    Node *temp, *keyNode = nullptr, *last;
    while (!q.empty()) {
        temp = q.front(); q.pop();

        if (temp->data == key)
            keyNode = temp;

        if (temp->left) {
            last = temp;
            q.push(temp->left);
        }
        if (temp->right) {
            last = temp;
            q.push(temp->right);
        }
    }
    if (keyNode) {
        keyNode->data = temp->data;
        if (last->right == temp) last->right = nullptr;
        else last->left = nullptr;
        delete temp;
    }
    return root;
}
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    root = deleteNode(root, 2);
    cout << "Deleted node with value 2" << endl;
    return 0;
}
