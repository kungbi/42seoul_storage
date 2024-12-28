#include "FragTrap.hpp"

int main(void) {
	FragTrap fragTrap("John");
	FragTrap fragTrap2(fragTrap);

	fragTrap.attack("enemy");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();

	for (int i = 0; i < 100; i++) {
		fragTrap2.attack("enemy");
	}

	std::cout << "---------------------------------" << std::endl;
	std::cout << "Points: " << fragTrap2.getHitPoints() << std::endl;
	std::cout << "Energy: " << fragTrap2.getEnergyPoints() << std::endl;
	fragTrap2.beRepaired(5);
	fragTrap2.highFivesGuys();

	return 0;
}