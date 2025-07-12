#include <iostream>
// Include unordered map to store node values and pointer
#include <unordered_map>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string n) {
        name = n;
        left = nullptr;
        right = nullptr;
    }
};

class Tree {
public:
    Node* root;
    unordered_map<string,Node*> nodes; // Map called nodes

    Tree() {
        root = nullptr;
    }

    void add_root(string name) {
        root = new Node(name);
        nodes[name]=root;
    }

    void add_left(string parent_name, string child_name) {
        Node* parent = nodes[parent_name];
        parent->left = new Node(child_name);
        nodes[child_name] = parent->left;
    }

    void add_right(string parent_name, string child_name) {
        Node* parent = nodes[parent_name];
        parent->right = new Node(child_name);
        nodes[child_name] = parent->right; 
    }
};

int main() {
    Tree tree;

    tree.add_root("A");
    tree.add_left("A", "B");
    tree.add_right("A", "C");
    tree.add_left("B", "D");
    tree.add_right("B", "E");
    tree.add_left("C", "F");
    tree.add_right("C", "G");

    cout << "Root: " << tree.nodes["A"]->name << endl;
    cout << "Left child of A: " << tree.nodes["A"]->left->name << endl;
    cout << "Right child of A: " << tree.nodes["A"]->right->name << endl;
    cout << "Left child of B: " << tree.nodes["B"]->left->name << endl;
    cout << "Right child of B: " << tree.nodes["B"]->right->name << endl;
    cout << "Left child of C: " << tree.nodes["C"]->left->name << endl;
    cout << "Right child of C: " << tree.nodes["C"]->right->name << endl;
    
    Node* A = tree.nodes["A"];
    cout << "Accessed root via name 'A': " << A->name << endl;

    return 0;
}
