#include "easyfind.hpp"
#include <vector>
#include <iostream>
#include <string>

int main() {
	std::vector<int> vec;

	for (int i = 0; i < 10; i++) {
		vec.push_back(i);
	}

	std::cout << *(easyfind(vec, 9)) << std::endl;
	
	try {
		std::cout << *(easyfind(vec, 10)) << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}