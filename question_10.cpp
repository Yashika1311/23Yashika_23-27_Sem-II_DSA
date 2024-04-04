#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return -1;
        }
        int dequeuedValue = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return dequeuedValue;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "queue is empty" << endl;
            return;
        }
        cout << "queue: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    char choice;
    int value;
    do {
        cout << "1. enqueue\n";
        cout << "2. dequeue\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "enter element to enqueue: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case '2':
                if (!queue.isEmpty()) {
                    cout << "dequeued value: " << queue.dequeue() << endl;
                }
                break;
            case '3':
                queue.display();
                break;
            case '4':
                cout << "exited!" << endl;
                break;
            default:
                cout << "invalid choice" << endl;
        }
    } while (choice != '4');
    return 0;
}
