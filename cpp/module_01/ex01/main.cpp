#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int n = 4;

	zombies = zombieHorde(n, "zombie");

	if (!zombies)
		return (0);

	for (int i = 0; i < n; i++)
		zombies[i].announce();
		
	delete [] zombies;
}