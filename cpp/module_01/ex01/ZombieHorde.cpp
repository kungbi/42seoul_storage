#include "Zombie.hpp"

void validate(int n) {
	if (n <= 0)
	{
		std::cout << "Please enter a positive value\n";
		throw std::exception();
	}
}

Zombie* zombieHorde(int n, std::string name)
{
	validate(n);
	Zombie* zombies = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		zombies[i].setName(name + std::to_string(i)); 
	}
	return (zombies);
}