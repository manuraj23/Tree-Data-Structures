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
void insert(Node* root, int val) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (!temp->left) {
            temp->left = new Node(val);
            return;
        } else q.push(temp->left);
        if (!temp->right) {
            temp->right = new Node(val);
            return;
        } else q.push(temp->right);
    }
}
int main() {
    Node* root = new Node(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);

    cout << "Inserted 2, 3, 4 in tree rooted at " << root->data << endl;
    return 0;
}
