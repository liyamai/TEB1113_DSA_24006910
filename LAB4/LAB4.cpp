#include <iostream>
using namespace std;

struct Process {
    int pid;
    int burstTime;
    int remainingTime;
    Process* next;
};

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void createInitialList() {
        for (int i = 1; i <= 5; ++i) {
            insertAtEnd(i);
        }
    }

    void display() {
        if (!tail) {
            return;
        }
        Node* temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if (!tail) {
            tail = newNode;
            tail->next = tail;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteFirst() {
        if (!tail) return;
        Node* head = tail->next;
        if (tail == head) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }

    void deleteLast() {
        if (!tail) return;
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
            return;
        }
        Node* current = tail->next;
        while (current->next != tail) {
            current = current->next;
        }
        current->next = tail->next;
        delete tail;
        tail = current;
    }
};

class RoundRobinScheduler {
private:
    Process* head;

public:
    RoundRobinScheduler() : head(nullptr) {}

    void addProcess(int pid, int burstTime) {
        Process* newProc = new Process{pid, burstTime, burstTime, nullptr};
        if (!head) {
            head = newProc;
            head->next = head;
        } else {
            Process* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newProc;
            newProc->next = head;
        }
    }

    void simulate(int timeQuantum) {
        if (!head) {
            cout << "No processes to schedule." << endl;
            return;
        }

        cout << "Starting Round Robin Scheduling with time quantum = " << timeQuantum << endl;

        Process* current = head;
        Process* prev = nullptr;

        while (head) {
            cout << "Processing PID " << current->pid << " with remaining time " << current->remainingTime << endl;

            int execTime = min(current->remainingTime, timeQuantum);
            current->remainingTime -= execTime;
            cout << "Executed for " << execTime << " units. Remaining: " << current->remainingTime << endl;

            if (current->remainingTime == 0) {
                cout << "Process " << current->pid << " completed. Removing from queue." << endl;

                if (current == head && current->next == head) {
                    delete current;
                    head = nullptr;
                    break;
                } else {
                    Process* temp = head;
                    while (temp->next != current)
                        temp = temp->next;

                    temp->next = current->next;
                    if (current == head)
                        head = current->next;
                    delete current;
                    current = temp->next;
                }
            } else {
                current = current->next;
            }

            if (!head) break;

            cout << "Remaining processes: ";
            displayProcesses();
        }

        cout << "All processes completed." << endl;
    }

    void displayProcesses() {
        if (!head) {
            cout << "No processes." << endl;
            return;
        }
        Process* temp = head;
        do {
            cout << "[PID " << temp->pid << ", Remaining " << temp->remainingTime << "] ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList clist;
    cout << "Creating initial list with 5 nodes:" << endl;
    clist.createInitialList();
    clist.display();

    cout << "\nInserting 99 at beginning:" << endl;
    clist.display();

    cout << "\nInserting 88 at tail:" << endl;
    clist.insertAtEnd(88);
    clist.display();

    RoundRobinScheduler rr;
    rr.addProcess(1, 10);
    rr.addProcess(2, 4);
    rr.addProcess(3, 6);

    int quantum;
    cout << "\nEnter time quantum for round-robin: ";
    cin >> quantum;

    rr.simulate(quantum);

    return 0;
}
