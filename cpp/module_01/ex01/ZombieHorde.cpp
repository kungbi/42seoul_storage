#include "Zombie.hpp"
#include <sstream>

void validate(int n) {
	if (n <= 0)
	{
		std::cout << "Please enter a positive value\n";
		throw std::exception();
	}
}

std::string intToString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

Zombie* zombieHorde(int n, std::string name)
{
	validate(n);
	Zombie* zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		zombies[i].setName(name + intToString(i)); 
	}
	return (zombies);
}


