#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <cstring>
#include <cstdlib>

class RPN {
private:
    // A stack follows the Last In, First Out (LIFO) principle,
    // where a new element is added at one end (top) and an element is removed from that end only

    std::stack<int> stack;
    int performOperation(int operand1, int operand2, char op);
    bool isNumber(const std::string& str);

public:
    RPN();
    RPN(const RPN &);
    RPN& operator=(const RPN&);
    ~RPN();

    int processRPN(std::string expression);

    class ErrorException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};