#include "RPN.hpp"

RPN::RPN() {

}
RPN::RPN(const RPN &other) {
	this->stack = other.stack;
}

RPN& RPN::operator=(const RPN &other) {
	this->stack = other.stack;
    return (*this);
}

RPN::~RPN() {

}

// *** //

/* &endPtr: pointer to a character that will be set to the first
 * invalid character after the conversion. This allows checking if
 * the entire string was successfully converted. */

bool RPN::isNumber(const std::string& str) {
	char* endPtr;
	std::strtol(str.c_str(), &endPtr, 10);

	return (*endPtr == '\0');
}

int RPN::performOperation(int operand1, int operand2, char op) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
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
			long longNumber = atol(token.c_str());
			if (!(longNumber < INT_MAX && longNumber > INT_MIN))
				throw ErrorException();
			int n = atoi(token.c_str());
            if (n > 9)
                throw ErrorException();
            stack.push(n);
        }

        else if (token == "+" || token == "-" || token == "/" || token == "*")
        {
            if (stack.size() < 2)
                throw ErrorException();

            int operand2 = stack.top();
			stack.pop();
            int operand1 = stack.top();
			stack.pop();

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