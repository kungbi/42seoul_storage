#include "BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange(void) {
    coinMap.clear();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &bitcoinexchange) {
    *this = bitcoinexchange;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const &bitcoinexchange) {
    if (this == &bitcoinexchange)
        return *this;
    this->coinMap = bitcoinexchange.coinMap;
    this->first = bitcoinexchange.first;
    this->last = bitcoinexchange.last;
    return *this;
}

BitcoinExchange::BitcoinExchange(const char *coinData) {
    std::ifstream file(coinData);
    if (!file.is_open())
        throw std::invalid_argument("could not open file.");
    parseHeaderLine(file);
    parseCsvData(file);
    validateCoinMap();
    setDateRange();
}


void BitcoinExchange::calcBitcoin(const std::string &inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::invalid_argument("could not open file.");
    skipHeaderLine(file);
    processInputLines(file);
}

void BitcoinExchange::skipHeaderLine(std::ifstream &file)
{
    std::string header;
    std::getline(file, header);
    if (header.empty())
        throw std::invalid_argument("input file is empty.");
    if (header != "date | value")
        throw std::invalid_argument("Invalid header line.");
}

void BitcoinExchange::processInputLines(std::ifstream &file)
{
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        try
        {
            validate(line);

            std::string date = line.substr(0, 10);
            std::string valueStr = line.substr(13);
            float value = std::atof(valueStr.c_str());

            findDate(date, value);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}

// private

void BitcoinExchange::parseHeaderLine(std::ifstream &file) {
    std::string line;
    getline(file, line);
    if (line.empty())
        throw std::invalid_argument("coinMap is empty.");
    if (line != "date,exchange_rate")
        throw std::invalid_argument("Invalid header line.");
}

void BitcoinExchange::parseCsvData(std::ifstream &file) {
    std::string line;
    char *pos = NULL;

    while (getline(file, line)) {
        if (line.size() < 12 || isInvalidLine(line))
            throw std::invalid_argument("Invalid line in csv file.");

        std::string date = line.substr(0, 10);
        std::string valueStr = line.substr(11);

        if (line[10] != ',' || !isValidValue(valueStr) || !isValidDate(date))
            throw std::invalid_argument("Invalid Value or Date in csv file.");

        float value = std::strtof(valueStr.c_str(), &pos);
        if (value < 0)
            throw std::invalid_argument("not a positive number\n");

        fillCoinMap(date, value);
    }
}

void BitcoinExchange::validateCoinMap() {
    if (coinMap.empty())
        throw std::invalid_argument("coinMap is empty.");
}

void BitcoinExchange::setDateRange() {
    if (coinMap.empty())
        throw std::runtime_error("coinMap is empty. Cannot set date range.");
    this->first = coinMap.begin()->first;
    this->last = coinMap.rbegin()->first;
}


void BitcoinExchange::fillCoinMap(std::string date, float value) {
    if (coinMap.find(date) == coinMap.end())
        coinMap[date] = value;
    else
        throw std::invalid_argument("Already exists in map\n");
}

int BitcoinExchange::isInvalidLine(std::string line) {
    int i = 0;

    while (line[i]) {
        if (!(('0' <= line[i] && line[i] <= '9') || line[i] == '-'|| \
            line[i] == ',' || line[i] == '.'))
            return true;
        i++;
    }
    return false;
}

int BitcoinExchange::isValidDate(std::string date) {
    if (!(date[4] == '-' && date[7] == '-'))
        return false;

    int index = 0;
    while (date[index]) {
        if (index >= 0 && index <= 3)
        {
            if (index == 0)
                if (date[index] == '0')
                    return false;
            if (!('0' <= date[index] && date[index] <= '9'))
                return false;
        }
        else if ((index >= 5 && index <= 6) ||
            (index >= 8 && index <= 9))
        {
            if (!('0' <= date[index] && date[index] <= '9'))
                return false;
        }
        index++;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 1000)
        return false;
    if (month > 12 || month < 1)
        return false;
    if (day > 31 || day < 1)
        return false;

    if (month == 2)
    {
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            if (day > 29)
                return false;
        }
        else
        {
            if (day > 28)
                return false;
        }
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}


int BitcoinExchange::isValidValue(std::string value)
{
    if (value.empty())
        return false;

    int index = 0;
    int point = 0;

    // 첫 글자가 부호일 경우
    if (value[0] == '+' || value[0] == '-') {
        if (value.size() == 1)
            return false; // 부호만 있는 경우는 허용 안 함
        index++;
    }

    bool hasDigit = false;

    for (; value[index]; ++index) {
        if (value[index] == '.') {
            point++;
            if (point > 1)
                return false;
        } else if (value[index] >= '0' && value[index] <= '9') {
            hasDigit = true;
        } else {
            return false;
        }
    }

    return hasDigit;
}

void BitcoinExchange::outputelement()
{
    for(std::map<std::string, float>::iterator iter = coinMap.begin(); iter != coinMap.end(); iter++)
    {
        std::cout << iter->first << " " << iter->second << "\n";
    }
}

void BitcoinExchange::findDate(std::string line, float value)
{
    std::map<std::string, float>::iterator iter = coinMap.upper_bound(line);
    if (iter == coinMap.begin())
        printResult(iter, line, value);
    else
        printResult(--iter, line, value);
}

void BitcoinExchange::printResult(std::map<std::string, float>::iterator iter, std::string date, float value)
{
    std::cout << date << " => " << value << " = " << iter->second * value << "\n";
}

void BitcoinExchange::validate(std::string line)
{
    isLineTooShort(line);
    isValidDateFormat(line);
    isValidSeparator(line);
    isDateOutOfRange(line);
    isInvalidValue(line);
}

void BitcoinExchange::isLineTooShort(const std::string &line)
{
    if (line.length() < 10)
        throw std::invalid_argument("bad input => " + line);
}

void BitcoinExchange::isValidDateFormat(const std::string &line)
{
    if (!isValidDate(line.substr(0, 10)))
        throw std::invalid_argument("bad input => " + line.substr(0, 10));
}

void BitcoinExchange::isValidSeparator(const std::string &line)
{
    if (line.substr(10, 3) != " | ")
        throw std::invalid_argument("bad input => " + line.substr(10, 3));
}

void BitcoinExchange::isDateOutOfRange(const std::string &line)
{
    if (line.substr(0, 10) < first || line.substr(0, 10) > last)
        throw std::invalid_argument("date out of range => " + line.substr(0, 10));
}

void BitcoinExchange::isInvalidValue(const std::string &line)
{
    if (line.size() < 14 || !isValidValue(line.substr(13)))
        throw std::invalid_argument("bad input => " + line.substr(13));
    if (atol(line.substr(13).c_str()) < 0)
        throw std::invalid_argument("not a positive number.");
    if (atol(line.substr(13).c_str()) > 1000)
        throw std::invalid_argument("too large a number.");
}
