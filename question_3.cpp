#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main() {
    stack<char> s;
    string infix, postfix;
    
    // Map to store operator precedence
    map<char, int> precedence;
    precedence['+'] = precedence['-'] = 1;
    precedence['*'] = precedence['/'] = 2;

    cout << "enter an infix expression: ";
    getline(cin, infix);

    for (int i = 0; i < infix.length(); ++i) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        } else {
            while (!s.empty() && s.top() != '(' && precedence[c] <= precedence[s.top()]) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "postfix expression: " << postfix << endl;
    return 0;
}
