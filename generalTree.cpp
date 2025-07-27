#include <iostream>
#include <vector>
using namespace std;

class GeneralTree {
public:
    int data;
    vector<GeneralTree*> children;

    GeneralTree(int val) {
        data = val;
    }

    void addChild(GeneralTree* child) {
        children.push_back(child);
    }
};

int main() {
    GeneralTree* root = new GeneralTree(1);
    GeneralTree* child1 = new GeneralTree(2);
    GeneralTree* child2 = new GeneralTree(3);
    root->addChild(child1);
    root->addChild(child2);
    
    cout << "Root Node: " << root->data << endl;
    cout << "Children of Root: ";
    for (auto child : root->children)
        cout << child->data << " ";
}
