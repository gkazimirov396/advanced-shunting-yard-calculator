#include <iostream>
#include <queue>
#include <stack>
#include <string>

#include "tokenization.cpp"
#include "shunting_yard.cpp"
#include "evaluation.cpp"

using namespace std;

int main() {
    string input;

    while (true) {
        getline(cin, input);

        if (input[0] == 'q') {
            break;
        }
        else {
            queue<string> tokens = Tokenization::Tokenize(input);
            queue<string> output = ShuntingYard::TransformToRPN(tokens);

            double result = Evaluation::CalculateResult(output);
            cout << result << endl;
        }
    }

    return 0;
}