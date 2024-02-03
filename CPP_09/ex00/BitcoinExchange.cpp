#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database) {

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    database = other.database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {

}


void BitcoinExchange::readDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return ;
    }

    std::string text;

    if (!getline(file, text) || text != "date,exchange_rate")
    {
        file.close();
        std::cerr << "Error: empty or unsupported file " << filename << std::endl;
        return ;
    }
    while (getline (file, text)) {
        size_t pos = text.find(",");
        if (pos != std::string::npos) {
            std::string date = text.substr(0, pos);
            std::string value = text.substr(pos + 1);
			float rate = atof(value.c_str());

			if (isValidDate(date) && rate >= 0)
                database[date] = rate;
        }
    }
    file.close();
}

float BitcoinExchange::exchangeRate(const std::string& date)
{
    // The lower_bound function returns an iterator pointing to the key in the map container
    // which is equivalent to the value passed in the parameter
    std::map<std::string, float>::const_iterator closestDate = database.lower_bound(date);

    if (closestDate == database.begin() && date < closestDate->first)
        return 0.0;
    else if (closestDate == database.end())
        --closestDate;
    else if (date < closestDate->first)
        --closestDate;
    return closestDate->second;
}

void BitcoinExchange::bitcoinExchange(const std::string& str)
{
    size_t pos = str.find(" | ");
    if (pos != std::string::npos) {
        std::string date = str.substr(0, pos);
        std::string value = str.substr(pos + 3);

		float rate = atof(value.c_str());
        if (rate >= 0 && rate <= 1000)
        {
            if (isValidDate(date))
            {
                float res = exchangeRate(date) * rate;
                std::cout << date << " => " << value << " = " << res << std::endl;
            }
            else
                std::cout << "Error: bad input => " << str << std::endl;
        }
        else
        {
            if (rate < 0)
                std::cout << "Error: not a positive number." << std::endl;
            else
                std::cout << "Error: too large a number." << std::endl;
        }
    }
    else
        std::cout << "Error: bad input => " << str << std::endl;
}


void BitcoinExchange::processInputFile(const std::string& filename)
{
    bool databaseExists = false;
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file " << filename << std::endl;
        return ;
    }

    std::string text;

    if (!getline(file, text) || text != "date | value")
    {
        file.close();
        std::cerr << "Error: empty or unsupported file " << filename << std::endl;
        return ;
    }
    while (getline (file, text)) {
        bitcoinExchange(text);
        databaseExists = true;
    }
    if (!databaseExists)
        std::cerr << "Error: empty database " << filename << std::endl;
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string& dateString) {
    std::istringstream ss(dateString);
    char delimiter;

    int year, month, day;

    if (!(ss >> year >> delimiter >> month >> delimiter >> day) || (delimiter != '-'))
        return false;

    struct tm timeinfo = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    std::time_t time = std::mktime(&timeinfo);

    return time != -1 && timeinfo.tm_year + 1900 == year && timeinfo.tm_mon + 1 == month && timeinfo.tm_mday == day;
}

