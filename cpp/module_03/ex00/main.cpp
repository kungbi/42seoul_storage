#include "ClapTrap.hpp"

int main(void) {
	ClapTrap clapTrap("John");
	ClapTrap clapTrap2("Kaven");

	clapTrap.attack("ABC");
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);
	clapTrap2.attack("DEF");

	std::cout << std::endl;
	clapTrap.takeDamage(5);
	std::cout << "[LOG] ClapTrap " << clapTrap.getName() << " has " << clapTrap.getHitPoints()
		<< " hit points left and " << clapTrap.getEnergyPoints() << " energy points left" << std::endl;
		
	clapTrap.beRepaired(10);
	std::cout << "[LOG] ClapTrap " << clapTrap.getName() << " has " << clapTrap.getHitPoints()
		<< " hit points left and " << clapTrap.getEnergyPoints() << " energy points left" << std::endl;
	return 0;
}