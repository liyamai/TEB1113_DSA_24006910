#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next_pointer;
    Node* prev_pointer;
};

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;

public:
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next_pointer;
            delete current;
            current = next;
        }
    }

    void insert_node(Node* node) {
        node->next_pointer = nullptr;
        node->prev_pointer = nullptr;

        if (head == nullptr) {
            head = tail = node;
        } else {
            tail->next_pointer = node;
            node->prev_pointer = tail;
            tail = node;
        }
    }

    void insert_front(Node* node) {
        node->next_pointer = nullptr;
        node->prev_pointer = nullptr;

        if (head == nullptr) {
            head = tail = node;
        } else {
            node->next_pointer = head;
            head->prev_pointer = node;
            head = node;
        }
    }

    void delete_node(const string& name) {
        Node* current = head;
        while (current != nullptr) {
            if (current->name == name) {
                if (current->prev_pointer != nullptr)
                    current->prev_pointer->next_pointer = current->next_pointer;
                else
                    head = current->next_pointer;

                if (current->next_pointer != nullptr)
                    current->next_pointer->prev_pointer = current->prev_pointer;
                else
                    tail = current->prev_pointer;

                delete current;
                return;
            }
            current = current->next_pointer;
        }
    }

    void display_list() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->name;
            if (current->next_pointer != nullptr) {
                cout << " <-> ";
            }
            current = current->next_pointer;
        }
        cout << endl;
    }

    void display_reverse() {
        Node* current = tail;
        while (current != nullptr) {
            cout << current->name;
            if (current->prev_pointer != nullptr) {
                cout << " <-> ";
            }
            current = current->prev_pointer;
        }
        cout << endl;
    }
};

int main() {
    LinkedList std_names;

    Node* node1 = new Node{"Ali", nullptr, nullptr};
    Node* node2 = new Node{"Alice", nullptr, nullptr};
    Node* node3 = new Node{"Ahmed", nullptr, nullptr};

    std_names.insert_node(node1);
    std_names.insert_node(node2);
    std_names.insert_node(node3);

    cout << "Original list (forward): ";
    std_names.display_list();

    cout << "Original list (reverse): ";
    std_names.display_reverse();

    std_names.delete_node("Alice");

    cout << "After deletion (forward): ";
    std_names.display_list();

    cout << "After deletion (reverse): ";
    std_names.display_reverse();

    return 0;
}
