// CS400HW5Question1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// finish all the TODOs and use the code from main() to test your result:


#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperand(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

string postfixToInfix(string postfix) {
    stack<string> st;
    for (char c : postfix) {
        if (isOperand(c)) {
            string operand(1, c);
            st.push(operand);
        }
        else {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            string temp = "(" + op1 + c + op2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}

