#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { 
	first = "1000-01-01";
	last = "9999-12-31";
}

BitcoinExchange::~BitcoinExchange() {}

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

void BitcoinExchange::showErrorMessage(std::string message) {
	std::cout << message << std::endl;
	std::exit(1);
}

BitcoinExchange::BitcoinExchange(const char *data) {
	std::ifstream file;

	file.open(data, std::ios::in);
	if (!file.is_open())
		showErrorMessage("Error: could not open file.");
	
	std::string line;
	getline(file, line);
	if (line.empty())
		showErrorMessage("Error: coinMap is empty.");

	char *pos = NULL;
	while (getline(file, line)) {

		if(line.size() < 12 || csv_line_check(line))
			showErrorMessage("Error: Invalid in csv file.");

		if (!isValidValue(line.substr(11)) || line[10] != ',')
			showErrorMessage("Error: Invalid Value in csv file.");

		if (!isValidDate(line.substr(0, 10)))
			showErrorMessage("Error: Invalid Date in csv file.");
		if (std::strtof(line.substr(11).c_str(), &pos) < 0)
			showErrorMessage("Error: not a positive number\n");
		fillCoinMap(line.substr(0, 10), std::strtof(line.substr(11).c_str(), &pos));
	}

	if (coinMap.empty())
		showErrorMessage("Error: coinMap is empty.");
	this->first = coinMap.begin()->first;
	this->last = coinMap.rbegin()->first;
}

void BitcoinExchange::fillCoinMap(std::string date, float value) {
	if (coinMap.find(date) == coinMap.end())
		coinMap[date] = value;
	else
		showErrorMessage("Error: Already exists in map\n");
}

int BitcoinExchange::csv_line_check(std::string line) {
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
	int index = 0;
	int point = 0;

	if (value.empty())
		return true;
	if (value[0] == '-' || value[0] == '+')
		return true;
	while (value[index] != '\0')
	{
		if (point > 1)
			return false;
		if (value[index] < '0' || value[index] > '9')
		{
			if (value[index] == '.')
				point++;
			else
				return false;
		}
		index++;
	}


	return true;
}


void BitcoinExchange::outputelement()
{
	for(std::map<std::string, float>::iterator iter = coinMap.begin(); iter != coinMap.end(); iter++)
	{
		std::cout << iter->first << " " << iter->second << "\n";
	}
}

void BitcoinExchange::calcBitcoin(const char *argv)
{
	std::ifstream file;
	file.open(argv, std::ios::in);
	if (!file.is_open())
		showErrorMessage("Error: could not open file.");

	std::string line;
	getline(file, line);
	if (line.empty())
		showErrorMessage("Error: coinMap is empty.");

	while (getline(file, line))
	{
		if (line.empty())
			continue;
		handleError(line);
		findDate(line.substr(0, 10), std::atof(line.substr(13).c_str()));
	}

}

void BitcoinExchange::findDate(std::string line, float value)
{
	std::map<std::string, float>::iterator iter = coinMap.upper_bound(line);
	iter--;
	printResult(iter, line, value);
}

void BitcoinExchange::printResult(std::map<std::string, float>::iterator iter, std::string date, float value)
{
	std::cout << date << " => " << value << " = " << iter->second * value << "\n";
}

void BitcoinExchange::handleError(std::string line)
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
