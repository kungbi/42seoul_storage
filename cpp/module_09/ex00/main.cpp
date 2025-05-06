#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Wrong argument!";
		return 1;
	}

	BitcoinExchange bitcoinExchange("data.csv");
	std::string inputFile = argv[1];
	try {
		bitcoinExchange.calcBitcoin(inputFile);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}