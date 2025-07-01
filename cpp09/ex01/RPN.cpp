#include "RPN.hpp"
#include <cctype>
#include <csignal>
#include <cstdio>
#include <stdexcept>

RPN::RPN()
{

}

RPN::RPN(const RPN &src)
{
    this->_stack = src._stack;
}

RPN::~RPN() {}

RPN &RPN::operator=(const class RPN &src)
{
    if (this != &src)
        this->_stack = src._stack;
    return *this;
}

int whichToken(char c)
{
    if (c == '+')
        return 0;
    else if (c == '-')
        return 1;
    else if (c == '/')
        return 2;
    else if (c == '*')
        return 3;

    return -1;
}

double RPN::calculate(void)
{
 //TODO actually do the iterative method of calculation while stack.size > 1
}

double RPN::processRPN(const std::string &str)
{
    std::istringstream ss(str);
    int turn = -1;

    while (ss.peek() != '\0' && ss.peek() != EOF)
    {
        char current = ss.get();
        if (current != ' ' && !std::isdigit(current) && whichToken(current) == -1)
            throw std::runtime_error("Invalid input!");
        if (current == ' ' && turn == 1)
            turn *= -1;
        else if (current != ' ' && turn == -1)
        {
            turn *= -1;
            _stack.push(current);
        }
        else
            throw std::runtime_error("Invalid input!");
    }

    //reverse the friggin thing
    std::stack<char> tempStack;
    while (!_stack.empty()) {
        tempStack.push(_stack.top());
        _stack.pop();
    }
    _stack = tempStack;

    return (calculate());
}
