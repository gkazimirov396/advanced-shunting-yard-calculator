#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

class Evaluation {
public:
    static double ChooseOperation(const string& operation, double operand1, double operand2) {
        switch (operation[0]) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        case 'm':
            if (operation == "min") return min(operand1, operand2);
            if (operation == "max") return max(operand1, operand2);
        case 'p':
            return pow(operand1, operand2);
        default:
            return 0;
        }
    }

    static double CalculateResult(queue<string>& tokens) {
        stack<double> stack;

        while (!tokens.empty()) {
            string token = tokens.front();
            tokens.pop();

            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                stack.push(stod(token));
            }
            else if (token == "abs") {
                double operand = stack.top();
                stack.pop();

                stack.push(abs(operand));
            }
            else {
                double operand2 = stack.top();
                stack.pop();

                double operand1 = stack.top();
                stack.pop();

                stack.push(ChooseOperation(token, operand1, operand2));
            }
        }

        return stack.top();
    }
};