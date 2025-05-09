#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <cstdlib>


class BitcoinExchange
{
private:
    std::map < std::string , float> coinMap;
    std::string first;
    std::string last;

    void isLineTooShort(const std::string &line);
    void isValidDateFormat(const std::string &line);
    void isValidSeparator(const std::string &line);
    void isDateOutOfRange(const std::string &line);
    void isInvalidValue(const std::string &line);

    void validate(std::string line);

    void parseHeaderLine(std::ifstream &file);
    void parseCsvData(std::ifstream &file);
    void validateCoinMap();
    void setDateRange();

    void skipHeaderLine(std::ifstream &file);
    void processInputLines(std::ifstream &file);

    BitcoinExchange(void);

public:
    ~BitcoinExchange(void);
    BitcoinExchange(BitcoinExchange const &bitcoinexchange);
    BitcoinExchange &operator=(BitcoinExchange const &bitcoinexchange);
    BitcoinExchange(const char *data);

    int isInvalidLine(std::string line);
    int isValidDate(std::string date);
    int isValidValue(std::string value);

    void fillCoinMap(std::string date, float value);


    void outputelement();

    void calcBitcoin(const std::string &inputFile);
    void findDate(std::string line, float value);
    void printResult(std::map<std::string, float>::iterator iter, std::string date, float value);
};

#endif