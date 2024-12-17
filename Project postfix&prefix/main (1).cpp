#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <sstream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}


double applyOp(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a, b);
        default: return 0;
    }
}


string infixToPostfix(const string &infix) {
    stack<char> ops;
    string postfix = "";
    bool prevWasOperator = true;

    for (size_t i = 0; i < infix.size(); i++) {
        char c = infix[i];

        if (isdigit(c) || c == '.') {

            while (i < infix.size() && (isdigit(infix[i]) || infix[i] == '.')) {
                postfix += infix[i];
                i++;
            }
            postfix += " ";
            i--;
            prevWasOperator = false;
        } else if (c == '(') {

            ops.push(c);
            prevWasOperator = true;
        } else if (c == ')') {

            while (!ops.empty() && ops.top() != '(') {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            if (!ops.empty() && ops.top() == '(') ops.pop();
            prevWasOperator = false;
        } else if (c == 'x') {
            postfix += "x ";
            prevWasOperator = false;
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {

            if (prevWasOperator && c == '-') {
                postfix += "-";
                prevWasOperator = false;
                continue;
            }
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                postfix += ops.top();
                postfix += " ";
                ops.pop();
            }
            ops.push(c);
            prevWasOperator = true;
        }
    }

    while (!ops.empty()) {
        postfix += ops.top();
        postfix += " ";
        ops.pop();
    }

    return postfix;
}

string infixToPrefix(const string &infix) {
    stack<string> ops;
    stack<string> operands;

    for (size_t i = 0; i < infix.size(); i++) {
        if (isdigit(infix[i])) {
            string number = "";
            while (i < infix.size() && (isdigit(infix[i]) || infix[i] == '.')) {
                number += infix[i];
                i++;
            }
            i--;
            operands.push(number);
        } else if (infix[i] == '(') {
            ops.push(string(1, infix[i]));
        } else if (infix[i] == ')') {
            while (!ops.empty() && ops.top() != "(") {
                string op = ops.top();
                ops.pop();

                string operand2 = operands.top();
                operands.pop();

                string operand1 = operands.top();
                operands.pop();

                string result = op + " " + operand1 + " " + operand2;
                operands.push(result);
            }
            ops.pop();
        } else if (precedence(infix[i])) {
            string op(1, infix[i]);
            while (!ops.empty() && precedence(ops.top()[0]) >= precedence(op[0])) {
                string topOp = ops.top();
                ops.pop();

                string operand2 = operands.top();
                operands.pop();

                string operand1 = operands.top();
                operands.pop();

                string result = topOp + " " + operand1 + " " + operand2;
                operands.push(result);
            }
            ops.push(op);
        }
    }

    while (!ops.empty()) {
        string topOp = ops.top();
        ops.pop();

        string operand2 = operands.top();
        operands.pop();

        string operand1 = operands.top();
        operands.pop();

        string result = topOp + " " + operand1 + " " + operand2;
        operands.push(result);
    }

    return operands.top();
}

double evaluatePostfix(const string &postfix, double xValue) {
    stack<double> values;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {

            double number = stod(token);
            values.push(number);
            cout << "Pushed: " << number << " | Top of stack: " << values.top() << endl;
        } else if (token == "x") {
            cout<<"x detected,pushing value  :"<<xValue<<endl;
            values.push(xValue);
            cout << "Pushed: " << xValue << " | Top of stack: " << values.top() << endl;
        } else if (token.size() == 1) {
            double b = values.top();
            values.pop();
            double a = values.top();
            values.pop();
            double result = applyOp(a, b, token[0]);
            values.push(result);
            cout << "Applied operator '" << token[0] << "' | Result pushed: " << result << " | Top of stack: " << values.top() << endl;
        }
    }


    cout << "Final result: " << values.top() << endl;
    return values.top();
}

void plotGraph(const string &postfix) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plot");
    window.setFramerateLimit(60);

    sf::VertexArray axes(sf::Lines, 4);
    axes[0].position = sf::Vector2f(400, 0); // y-axis
    axes[1].position = sf::Vector2f(400, 600);
    axes[2].position = sf::Vector2f(0, 300); // x-axis
    axes[3].position = sf::Vector2f(800, 300);
    for (int i = 0; i < 4; i++) axes[i].color = sf::Color::Black;

    sf::VertexArray points(sf::Points);
    float scale = 50.0f; // scale factor

    double xStart = -10.0, xEnd = 10.0, xStep = 0.01;

    for (double x = xStart; x <= xEnd; x += xStep) {
       cout << "Evaluating for x = " << x << endl;
        float yPostfix = evaluatePostfix(postfix, x);
        cout << "Top of stack (y value): " << yPostfix << endl;
        float screenX = 400 + x * scale;
        float screenY = 300 - yPostfix * scale;

        if (screenY >= 0 && screenY <= 600) {
            points.append(sf::Vertex(sf::Vector2f(screenX, screenY), sf::Color::Red));
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        window.draw(axes);
        window.draw(points);
        window.display();
    }
}
int main() {
    string infix;
    cout << "Enter the infix expression (e.g., 2*(3-1+5^2) or 3*x-1): ";
    getline(cin, infix);

    bool containsX = (infix.find('x') != string::npos);

    string postfix = infixToPostfix(infix);

    string prefix = infixToPrefix(infix);

    if (containsX) {
        cout << "Expression in postfix form: " << postfix << endl;
        cout << "Expression in prefix form: " << prefix << endl;

        char choice;
        cout << "Do you want to provide a value for x? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            double xValue;
            cout << "Enter value of x: ";
            cin >> xValue;

            cout << "Evaluating with x = " << xValue << endl;
            double result = evaluatePostfix(postfix, xValue);
            cout << "Final result: " << result << endl;
        } else {
            cout << "Drawing graph..." << endl;
            plotGraph(postfix);
        }
    } else {
        cout << "Expression in postfix form: " << postfix << endl;
        cout << "Expression in prefix form: " << prefix << endl;

        double result = evaluatePostfix(postfix, 0);
        cout << "The result of the expression is: " << result << endl;
    }

    return 0;
}
