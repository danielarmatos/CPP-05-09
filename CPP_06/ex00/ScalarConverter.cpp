#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter&) {
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &) {
    return (*this);
}

ScalarConverter::~ScalarConverter() {
}

// -------------------------- //

static void printOutput(char* c, int* i, float* f, double* d)
{
    // Char
    if (c == NULL)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(*c))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << *c << "'" << std::endl;

    // Int
    if (i == NULL)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << *i << std::endl;

    // Float
    if (f == NULL)
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::stringstream str_f;
        str_f << *f;
        if (*f != std::numeric_limits<float>::infinity() &&
            *f != std::numeric_limits<float>::quiet_NaN() &&
            int(*f * 10) % 10 == 0)
            str_f << ".0";
        std::cout << "float: " << str_f.str() << "f" << std::endl;
    }

    // Double
    if (d == NULL)
        std::cout << "double: impossible" << std::endl;
    else
    {
        std::stringstream str_d;
        str_d << *d;
        if (*d != std::numeric_limits<float>::infinity() &&
            *d != std::numeric_limits<float>::quiet_NaN() &&
            int(*d * 10) % 10 == 0)
            str_d << ".0";
        std::cout << "double: " << str_d.str() << std::endl;
    }
}

static void convertFromDouble(const double input)
{
    char c;
    int i;

    char *pC = NULL;
    int *pI = NULL;

    if (!(input > INT_MAX || input < INT_MIN || std::isnan(input)))
    {
		if (input < 256 && input >= 0)
		{
			c = static_cast<char>(input);
			pC = &c;
		}

        i = static_cast<int>(input);
        pI = &i;
    }

    float f = static_cast<float>(input);
    double d = input;

    printOutput(pC, pI, &f, &d);
}

static void convertFromFloat(const float input)
{
    char c;
    int i;

    char *pC = NULL;
    int *pI = NULL;

    if (!(input > 2147483647.0f || input < -2147483648.0f || std::isnan(input)))
    {
		if (input < 256 && input >= 0)
		{
			c = static_cast<char>(input);
			pC = &c;
		}
        i = static_cast<int>(input);
        pI = &i;
    }

    float f = input;
    double d = static_cast<double>(input);

    printOutput(pC, pI, &f, &d);
}

static void convertFromInt(std::string inputStr)
{
	char *pC = NULL;
	char* endptr;
	long longValue = strtol(inputStr.c_str(), &endptr, 10);

	if (*endptr != '\0' || longValue > INT_MAX || longValue < INT_MIN)
	{
		printOutput(NULL, NULL, NULL, NULL);
		return ;
	}
	int input = static_cast<int>(longValue);
	if (input < 256 && input >= 0)
	{
		char c = static_cast<char>(input);
		pC = &c;
	}
	else
		pC = NULL;
    int i = input;
    float f = static_cast<float>(input);
    double d = static_cast<double>(input);
    printOutput(pC, &i, &f, &d);
}

static void convertFromChar(const char input)
{
    char c = input;
    int i = static_cast<int>(input);
    float f = static_cast<float>(input);
    double d = static_cast<double>(input);
    printOutput(&c, &i, &f, &d);
}

static bool isValidString(const std::string& input, const std::string &allowedChars)
{
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
        if (allowedChars.find(*it) == std::string::npos) {
            return (false);
        }
    }
    return (true);
}

static void convertToActualType(const std::string& input)
{
    if (input.size() == 1 && !isdigit(input[0]))
        convertFromChar(input[0]);

    else if (isValidString(input, "0123456789+-"))
		convertFromInt(input);

    else if (input == "-inff" || input == "+inff" || input == "nanf" || (isValidString(input, "0123456789.f+-") && (input.find('f') == input.size() - 1) && input.find_first_of('.') == input.find_last_of('.')))
		convertFromFloat(atof(input.c_str()));

    else if ((input == "-inf" || input == "+inf" || input == "nan" || isValidString(input, "0123456789.+-")) && input.find_first_of('.') == input.find_last_of('.'))
		convertFromDouble(atof(input.c_str()));

    else
		printOutput(NULL, NULL, NULL, NULL);
}

void ScalarConverter::convert(const std::string& input)
{
    convertToActualType(input);
}
