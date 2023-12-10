#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
    std::cout << "ScalarConverter created (Copy constructor)" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &)
{
    std::cout << "ScalarConverter created (Copy assignment)" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter() {
}

// -------------------------- //

void ScalarConverter::convert(const std::string& input)
{
    // Convert to char
    if (input == "nan")
        std::cout << "char: impossible" << std::endl;
    else if (input.length() == 1 && std::isprint(input[0]) && isalpha(input[0])) {
        char charValue = input[0];
        std::cout << "char: " << charValue << std::endl;
    } else {
        std::cout << "char: Non displayable" << std::endl;
    }

    // Convert to int
   /* try {
        int intValue = std::stoi(input);
        std::cout << "int: " << intValue << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "int: impossible" << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "int: impossible" << std::endl;
    }*/

    try {
        size_t pos;
        int intValue = std::stoi(input, &pos);
        if (pos == input.length()) {
            std::cout << "int: " << intValue << std::endl;
        } else {
            throw std::invalid_argument("int: impossible");
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "int: impossible" << std::endl;
    }

    // Convert to float
    try {
        size_t pos;
        float floatValue;

        // Attempt to convert without the 'f' suffix
        floatValue = std::stof(input, &pos);

        // If successful, check if the remaining characters are valid
        if (pos == input.length()) {
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
            return;
        }
    } catch (const std::invalid_argument& e) {
        // Ignore and proceed to the next attempt
    }

    // If the conversion without 'f' fails, attempt to convert with 'f' removed
    try {
        size_t pos;
        float floatValue = std::stof(input.substr(0, input.length() - 1), &pos);
        if (pos == input.length() - 1) {
            std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue << "f" << std::endl;
        } else {
            throw std::invalid_argument("Invalid conversion");
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "float: impossible" << std::endl;
    }


    // Convert to double
    try {
        size_t pos;
        double doubleValue = std::stod(input, &pos);
        if (pos == input.length()) {
            std::cout << "double: " << std::fixed << std::setprecision(1) << doubleValue << std::endl;
        } else {
            throw std::invalid_argument("Invalid conversion");
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "double: impossible" << std::endl;
    }

}