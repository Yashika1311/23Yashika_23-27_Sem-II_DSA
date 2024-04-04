#include <iostream>
#include <stack>
#include <cctype> // For isdigit function
using namespace std;

int evaluate(const string& postfix) {
    stack<int> s;

    for (int i = 0; i < postfix.size(); ++i) {
        char c = postfix[i];
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            // Pop the top two operands from the stack
            int operand2 = s.top();
            s.pop();
            int operand1 = s.top();
            s.pop();

            // Perform the operation based on the operator
            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Invalid operator encountered: " << c << endl;
                    return -1; // Error case
            }
        }
    }

    // The result should be the only element left on the stack
    return s.top();
}

int main() {
    string postfixexp;
    cout << "enter postfix expression: ";
    getline(cin, postfixexp);
    cout << "result: " << evaluate(postfixexp) << endl;
    return 0;
}
