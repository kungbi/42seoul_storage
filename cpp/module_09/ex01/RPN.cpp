#include "RPN.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

RPN::RPN() {
    this->math_str = "";
}

RPN::RPN(const char *argv) {
    this->math_str = argv;
}

RPN::~RPN() {}

RPN::RPN(const RPN &rpn) {
    *this = rpn;
}

RPN &RPN::operator=(const RPN &rpn) {
    if (this != &rpn) {
        this->math_str = rpn.math_str;
        this->stack = rpn.stack;
    }
    return *this;
}

int RPN::takePop() {
    if (this->stack.empty())
        showMessage("Error: Attempted to pop from empty stack");
    int num = this->stack.top();
    this->stack.pop();
    return num;
}

int RPN::operand_calc(char op, int num1, int num2) {
    switch (op) {
        case '+': return num2 + num1;
        case '-': return num2 - num1;
        case '*': return num2 * num1;
        case '/':
            if (num1 == 0)
                showMessage("Error: Division by zero");
            return num2 / num1;
        default:
            showMessage("Error: Invalid operator");
    }
    return 0; // unreachable
}

int RPN::checkValue(char ch) {
    if (ch >= '0' && ch <= '9')
        return NUMBER;
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return OPERATOR;
    return INVALID;
}

int RPN::calcRpn() {
    if (!isValidExpression(this->math_str))
        showMessage("Error: Invalid expression");

    for (std::size_t i = 0; i < this->math_str.length(); ++i) {
        char ch = this->math_str[i];
        if (ch == ' ')
            continue;

        int type = checkValue(ch);
        if (type == NUMBER) {
            this->stack.push(ch - '0');
        } else if (type == OPERATOR) {
            if (this->stack.size() < 2)
                showMessage("Error: Not enough operands");
            int right = takePop();
            int left = takePop();
            this->stack.push(operand_calc(ch, right, left));
        } else {
            std::string msg = "Error: Invalid character '";
            msg += ch;
            msg += "'";
            showMessage(msg);
        }
    }

    if (this->stack.size() != 1)
        showMessage("Error: Malformed expression");

    return this->stack.top();
}

bool RPN::isValidExpression(const std::string &expr) {
    std::size_t i;
    int operands = 0;
    int operators = 0;

    for (i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        if (ch == ' ')
            continue;
        if (ch >= '0' && ch <= '9')
            ++operands;
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            ++operators;
        else
            return false;
    }
    return operands == operators + 1;
}

void RPN::showMessage(const std::string &msg) {
    std::cout << msg << std::endl;
    std::exit(1);
}
