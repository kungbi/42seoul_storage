#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &bitcoinexchange);
	BitcoinExchange &operator=(BitcoinExchange const &bitcoinexchange);


	BitcoinExchange(const char *data);
	int csv_line_check(std::string line);
	int isValidDate(std::string date);
	int isValidValue(std::string value);


	void showErrorMessage(std::string message);
	void fillCoinMap(std::string date, float value);


	void outputelement();

	void calcBitcoin(const char *argv);
	void findDate(std::string line, float value);
	void printResult(std::map<std::string, float>::iterator iter, std::string date, float value);
};

#endif