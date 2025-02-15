#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str) {
	try {
		double num = std::stod(str);

		std::cout << num << std::endl;
	} catch (std::exception &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
