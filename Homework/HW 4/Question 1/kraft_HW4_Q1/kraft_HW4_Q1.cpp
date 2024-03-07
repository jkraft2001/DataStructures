#include <iostream>
#include <stack>
#include <string>

bool isBalanced(const std::string& parentheses) {
    std::stack<char> stk;

    for (char c : parentheses) {
        if (c == '(' || c == '<') {
            stk.push(c);
        }
        else if (c == ')' || c == '>') {
            if (stk.empty() || (c == ')' && stk.top() != '(') || (c == '>' && stk.top() != '<')) {
                return false;
            }
            else {
                stk.pop();
            }
        }
    }

    return stk.empty();
}

int main() {
    // Test cases
    std::string testCases[] = {
        "<>()<()>(<>)",
        "(<)>",
        "><><",
        "())",
        "<<>",
        "<><<>>()(())"
    };

    for (const std::string& test : testCases) {
        if (isBalanced(test)) {
            std::cout << test << " is balanced." << std::endl;
        }
        else {
            std::cout << test << " is not balanced." << std::endl;
        }
    }

    return 0;
}

