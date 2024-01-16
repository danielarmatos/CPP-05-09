#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <climits>
#include <sstream>
#include <cmath>
#include <string>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter &operator=(const ScalarConverter&);
    ~ScalarConverter();

public:
    static void convert(const std::string& literal);
};