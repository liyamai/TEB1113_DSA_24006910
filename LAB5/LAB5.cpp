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

class Stack{
    public:
    Node* top;
    int maxSize;
    int currentSize=0;
    
    Stack(int size){
        top=nullptr;
        maxSize=size;
        currentSize=0;
        
    }
    
    bool isFull(){
        return currentSize==maxSize;
    }
    
    void push(string name){
        if(isFull()){
            cout << "Full. Cannot push new elements.";
            return;
        }
        
        Node* newNode=new Node(name);
        newNode->nextptr=top;
        top=newNode;
        currentSize++;
        cout << "Pushed " <<top->name <<" successfully." <<endl;
    }
    
    void peek(){
        if (top==nullptr){
            cout << "Stack empty."<<endl;
            return;
        } else{
            cout << "Top: " << top->name << endl;
            return;
        }
    }
    
    void pop(){
        if (top==nullptr){
            cout << "Stack empty. Cannot pop." <<endl;
            return;
        }
        
        Node* temp=top;
        top = top->nextptr;
        cout << "Popped: " << temp->name <<endl;
        delete temp;
        currentSize--;
    }
};

int main(){
    cout << "Stack" << endl;
    Stack stack(5);
    
    // Benedict Timothy Carlton Cumberbatch
    stack.push("Benedict");
    stack.push("Timothy");
    stack.push("Carlton");
    stack.push("Cumberbatch");
    
    stack.peek();
    stack.pop();
    
    cout << "Stack after pop:"<<endl;
    stack.peek();
    
    return 0;
}
