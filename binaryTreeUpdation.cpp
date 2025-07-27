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

bool update(Node* root, int oldVal, int newVal) {
    if (!root) return false;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front(); q.pop();

        if (temp->data == oldVal) {
            temp->data = newVal;
            return true;
        }

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }

    return false;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    if (update(root, 2, 20))
        cout << "Updated node value 2 to 20" << endl;
    else
        cout << "Value not found." << endl;

    return 0;
}
