#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <ctime>
#include <limits>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, float> database;

    void bitcoinExchange(const std::string& str);
    bool isValidDate(const std::string& dateString);
    float exchangeRate(const std::string& date);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void readDatabase(const std::string& filename);
    void processInputFile(const std::string& filename);


};