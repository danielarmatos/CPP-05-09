#include "RPN.hpp"

RPN::RPN() {

}
RPN::RPN(const RPN&) {
}

RPN& RPN::operator=(const RPN&) {
    return (*this);
}

RPN::~RPN() {

}


// *** //

bool RPN::isNumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}

int RPN::performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                throw ErrorException();
            }
        default:
            throw ErrorException();
    }
}

int RPN::processRPN(std::string expression)
{
    std::istringstream stream(expression);
    std::string token;

    while (stream >> token)
    {
        if (isNumber(token))
        {
            int n = std::stoi(token);
            if (n > 9)
                throw ErrorException();
            stack.push(n);
        }

        else if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            if (stack.size() < 2)
                throw ErrorException();

            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            int result = performOperation(operand1, operand2, token[0]);
            stack.push(result);
        }
        else
            throw ErrorException();
    }
    if (stack.size() == 1)
        return stack.top();
    else
        throw ErrorException();
}

const char* RPN::ErrorException::what() const throw()
{
    return ("Error");
}