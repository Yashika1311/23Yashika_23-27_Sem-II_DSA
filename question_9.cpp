#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "stack: ";
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
    char choice;
    int value;
    do {
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. display\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "enter value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case '2':
                cout << "popped value: " << stack.pop() << endl;
                break;
            case '3':
                stack.display();
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
