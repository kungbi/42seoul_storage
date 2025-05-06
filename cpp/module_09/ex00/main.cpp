#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc >= 3) {
		std::cout << "Wrong argument!";
		return 1;
	}

	BitcoinExchange bitcoinExchange("data.csv");
	try {
		bitcoinExchange.calcBitcoin(argv[1]);
	} catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}