#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
    private:
        std::stack<char> _stack;
        double calculate(void);


    public:
        RPN();
        RPN(const RPN &src);
        ~RPN();

        RPN &operator=(const RPN &src);

        double processRPN(const std::string &str);

};

#endif
