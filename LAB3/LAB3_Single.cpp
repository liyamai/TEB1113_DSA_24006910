#include <iostream>
using namespace std;

struct Node {
    string name;        // Node value
    Node* next_pointer; // Pointer to next node (The * for next_pointer)
    Node* prev_pointer; // Pointer to previous node (for doubly linked list)
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    // Insert at the end of the list
    void insert_node(Node* node) {
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next_pointer = node;
            node->prev_pointer = tail;
            tail = node;
        }
        node->next_pointer = nullptr;
    }

    // Delete a node by value
    void delete_node(string name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                if (current->prev_pointer) {
                    current->prev_pointer->next_pointer = current->next_pointer;
                } else {
                    head = current->next_pointer;
                }
                if (current->next_pointer) {
                    current->next_pointer->prev_pointer = current->prev_pointer;
                } else {
                    tail = current->prev_pointer;
                }
                delete current;
                return;
            }
            current = current->next_pointer;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next_pointer;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList std_names;

    // Create nodes dynamically
    Node* node1 = new Node{"Ali"};
    Node* node2 = new Node{"Alice"};
    Node* node3 = new Node{"Ahmed"};

    // Insert nodes
    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);

    // Display list
    cout << "Original list: ";
    std_names.display_list();

    // Delete node
    std_names.delete_node("Alice");
    cout << "After deletion: ";
    std_names.display_list();

    // Clean up remaining nodes
    delete node1;
    delete node3;

    return 0;
}
