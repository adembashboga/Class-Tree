#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    Node* root;
    void add(Node*& node, int value) 
    {
        if (!node) {
            node = new Node(value);
        }
        else if (value < node->value) 
        {
            add(node->left, value);
        }
        else 
        {
            add(node->right, value);
        }
    }
    void print(Node* node) const 
    {
        if (!node) return;
        print(node->left);            
        cout << node->value << " ";
        print(node->right);        
    }
public:
    Tree() : root(nullptr) {}
    void add(int value) 
    {
        add(root, value);
    }

    void print() const 
    {
        print(root);
        cout << endl;
    }
};

int main() {
    Tree tree;
    tree.add(5);
    tree.add(3);
    tree.add(7);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(8);

    cout << "Печать дерева: ";
    tree.print();
}
