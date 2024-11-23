#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class ShuntingYard {
public:
    static int Precedence(const string& op) {
        switch (op[0]) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case 'm':
        case 'p':
        case 'a':
            return 3;
        default:
            return 0;
        }
    }

    static queue<string> TransformToRPN(queue<string>& tokens) {
        queue<string> queueOutput;
        stack<string> notationStack;

        while (!tokens.empty()) {
            string token = tokens.front();
            tokens.pop();

            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                queueOutput.push(token);
            }
            else if (token == ",") {
                while (!notationStack.empty() && notationStack.top() != "(") {
                    queueOutput.push(notationStack.top());
                    notationStack.pop();
                }
            }
            else if (token == "(") {
                notationStack.push(token);
            }
            else if (token == ")") {
                while (!notationStack.empty() && notationStack.top() != "(") {
                    queueOutput.push(notationStack.top());
                    notationStack.pop();
                }

                if (!notationStack.empty() && notationStack.top() == "(") {
                    notationStack.pop();
                }
            }
            else if (token == "min" || token == "max" || token == "pow" || token == "abs") {
                notationStack.push(token);
            }
            else {
                while (!notationStack.empty() && Precedence(token) <= Precedence(notationStack.top())) {
                    queueOutput.push(notationStack.top());
                    notationStack.pop();
                }

                notationStack.push(token);
            }
        }

        while (!notationStack.empty()) {
            queueOutput.push(notationStack.top());
            notationStack.pop();
        }

        return queueOutput;
    }
};