#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class Tokenization {
public:
    static queue<string> Tokenize(const string& numExpression) {
        const string operators = "+-*/";

        queue<string> queueTokens;
        stack<string> buffer;

        for (size_t i = 0; i < numExpression.length(); i++) {
            char element = numExpression[i];

            if (isdigit(element) || element == '.') {
                buffer.push(string(1, element));
            }
            else if (element == '(' || element == ')' || element == ',') {
                if (!buffer.empty()) {
                    string number;

                    while (!buffer.empty()) {
                        number = buffer.top() + number;
                        buffer.pop();
                    }

                    queueTokens.push(number);
                }

                queueTokens.push(string(1, element));
            }
            else if (operators.find(element) != string::npos) {
                if (i == 0 || (i > 0 && operators.find(numExpression[i - 1]) != string::npos) || numExpression[i - 1] == '(') {
                    buffer.push(string(1, element));
                }
                else {
                    if (!buffer.empty()) {
                        string number;

                        while (!buffer.empty()) {
                            number = buffer.top() + number;
                            buffer.pop();
                        }

                        queueTokens.push(number);
                    }

                    queueTokens.push(string(1, element));
                }
            }
            else if (numExpression.substr(i, 3) == "min" ||
                numExpression.substr(i, 3) == "max" ||
                numExpression.substr(i, 3) == "pow" ||
                numExpression.substr(i, 3) == "abs") {
                queueTokens.push(numExpression.substr(i, 3));
                i += 2;
            }
        }

        if (!buffer.empty()) {
            string number;

            while (!buffer.empty()) {
                number = buffer.top() + number;
                buffer.pop();
            }

            queueTokens.push(number);
        }

        return queueTokens;
    }
};