#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>

# define number 1
# define operand 2

enum {
    NUMBER,
    OPERATOR,
    INVALID
};

class RPN 
{
    private: 
        std::stack<int> stack;
        std::string math_str;

        bool isValidExpression(const std::string &expr);
        void showMessage(const std::string &msg);
    public:
        RPN();
        RPN(const char *argv);
        ~RPN();
        RPN&operator=(RPN const &rpn);
        RPN(RPN const &rpn);


        int checkValue(char math);
        int operand_calc(char op, int num1, int num2);
        int takePop();
        int handleError(std::string math);
        int calcRpn(void);
};

#endif