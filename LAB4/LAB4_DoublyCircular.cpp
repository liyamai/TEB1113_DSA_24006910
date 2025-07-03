#include <iostream>
#include <string>
using namespace std;

class Node{
   public:
   string name;
   // Doubly = ada nextptr & prevptr
   Node* nextptr;
   Node* prevptr;
   
   Node(string name){
       this->name=name;
       this->nextptr=nullptr;
       this->prevptr=nullptr;
       // Doubly = ada prevptr
   }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    
    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    
    void addElement(string name){
        Node* newNode = new Node(name);
        
        // In case, head is null
        if (head==nullptr){
            head = newNode;
            tail = newNode;
            // Circular linked list = tail's nextptr point to head
           head->nextptr=head;
           head->prevptr=head;
        } else {
            // If not, add to tail
            tail->nextptr=newNode;
            newNode->prevptr=tail;
            newNode->nextptr=head;
            head->prevptr=newNode;
            tail=newNode;
            }
    }
    
    void displayForward(){
        Node* current = head;
        if (head==nullptr){
            cout << "List is empty."<<endl;
            return;
        }
            do{
                cout << current->name << " -> ";
                current = current->nextptr;
            } while (current!=head);
            cout << "(Back at Head) "<< current->name << endl;
        }
        
    void displayBackward(){
        Node* current = tail;
        if (tail==nullptr){
            cout << "List is empty."<<endl;
            return;
        }
            do{
                cout << current->name << " -> ";
                current = current->prevptr;
            } while (current!=tail);
            cout << "(Back at Tail) "<< current->name << endl;
        }
    };


int main(){
    cout << "hello sire, this is my circular Linked List"<<endl;
    
    LinkedList list;
    
    list.addElement("Amy");
    list.addElement("Lou");
    list.addElement("Wood");
    
    cout << "List:"<< endl;
    list.displayForward();
    list.displayBackward();
    return 0;
}
