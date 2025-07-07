#include "RPN.hpp"
#include <cctype>
#include <csignal>
#include <cstdio>
#include <cstdlib>
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

int whichToken(std::string c)
{
    if (c == "+")
        return 0;
    else if (c == "-")
        return 1;
    else if (c == "/")
        return 2;
    else if (c == "*")
        return 3;

    return -1;
}

double RPN::getRes(double first, double second, std::string opsign)
{

    switch (whichToken(opsign))
    {
        case 0:
            return first + second;
        case 1:
            return first - second;
        case 2:
            if (second == 0)
                throw std::runtime_error("Can't divide over zero!");
            return first / second;
        case 3:
            return first * second;
        default: //-1
            throw std::runtime_error("Wrong operator in stack!");
    }
}

void RPN::getNbrs(double &first, double &second)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Not enough numbers!");
    second = _stack.top();
    _stack.pop();
    first = _stack.top();
    _stack.pop();
}

double RPN::processRPN(const std::string &str)
{
    std::stringstream	ss(str);
	std::string 		current;

	while (ss >> current) {
        if ((std::isdigit(current[0]) || whichToken(current) != -1))
        {
            if (std::isdigit(current[0]))
                _stack.push(std::strtod(current.c_str(), NULL));
            else if (whichToken(current) != -1)
            {
                if (_stack.size() < 2)
                    throw std::runtime_error("Too many operands!");
                double first, second;
                getNbrs(first, second);
                _stack.push(getRes(first, second, current));
            }
        }
        else
            throw std::runtime_error("Unrecognised input!");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Not enough operands!");
    return (_stack.top());
}
