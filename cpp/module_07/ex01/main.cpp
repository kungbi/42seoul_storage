#include "iter.hpp"

void printInt(int i) {
	std::cout << i << std::endl;
}

void printFloat(float f) {
	std::cout << f << std::endl;
}

void printString(std::string s) {
	std::cout << s << std::endl;
}

int main(void) {
	int intArray[] = {1, 2, 3, 4, 5};
	float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	iter(intArray, 5, printInt);
	std::cout << std::endl;

	iter(floatArray, 5, printFloat);
	std::cout << std::endl;

	iter(stringArray, 5, printString);
	std::cout << std::endl;

	return 0;
}