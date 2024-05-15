#include <iostream>
#include <stack>
#include <string>

int evaluatePostfix(const std::string& expression) {
    std::stack<int> stack;

    for (char ch : expression) {
        if (isdigit(ch)) {
            stack.push(ch - '0'); // Convert char to int
        } else {
            int val1 = stack.top();
            stack.pop();
            int val2 = stack.top();
            stack.pop();

            switch (ch) {
                case '+': stack.push(val2 + val1); break;
                case '-': stack.push(val2 - val1); break;
                case '*': stack.push(val2 * val1); break;
                case '/': stack.push(val2 / val1); break;
            }
        }
    }
    return stack.top();
}

int main() {
    std::string expression = "231*+9-";
    std::cout << "Postfix evaluation of " << expression << ": " << evaluatePostfix(expression) << std::endl;
    return 0;
}
