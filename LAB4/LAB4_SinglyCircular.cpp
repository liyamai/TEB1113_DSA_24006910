#include <iostream>
#include <string>
using namespace std;

class Node{
   public:
   string name;
   Node* nextptr;
   
   Node(string name){
       this->name=name;
       this->nextptr=nullptr;
   }
};

class LinkedList{
    // Create head and tail, set to null
    public: // kena declare public wey
    Node* head;
    Node* tail;
    
    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    
    // add function : adding new node
    void addElement(string name){
        Node* newNode = new Node(name); // temp
        
        // In case, head is null
        if (head==nullptr){
            head = newNode;
            tail = newNode;
            // Circular linked list = tail's nextptr point to head
            tail->nextptr=head;
        } else {
            // If not, add to tail
            tail->nextptr=newNode;
            newNode->nextptr=head;
            tail=newNode;
        }
    }
    
    // display function : display entire list
    void displayList(){
        // set a pointer to head first
        Node* current = head;
        // If head null, print empty
        if (head==nullptr){
            cout << "List is empty."<<endl;
            return;
        } else{
            do{
                cout << current->name << " -> ";
                // change to nextptr
                current = current->nextptr;
            // if normal list: while(current=!nullptr)
            // but in circular, stop when it points to head
            } while (current!=head);
            cout << head->name << endl;
        }
    }
};

int main(){
    cout << "hello sire, this is my circular Linked List"<<endl;
    
    LinkedList list;
    
    list.addElement("Amy");
    list.addElement("Lou");
    list.addElement("Wood");
    
    cout << "List:"<< endl;
    list.displayList();
    return 0;
}
