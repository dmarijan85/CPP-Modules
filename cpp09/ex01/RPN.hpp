#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
    private:
        std::stack<double> _stack;
        double calculate(void);
        void getNbrs(double &first, double &second);
        double getRes(double first, double second, char opsign);



    public:
        RPN();
        RPN(const RPN &src);
        ~RPN();

        RPN &operator=(const RPN &src);

        double processRPN(const std::string &str);

};

#endif
