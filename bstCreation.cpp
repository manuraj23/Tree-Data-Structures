#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    Node* root = new Node(10);
    cout << "BST root created with value: " << root->data << endl;
    return 0;
}
