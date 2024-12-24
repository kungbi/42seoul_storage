#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scavTrap("John");
	ScavTrap scavTrap2("Kaven");

	scavTrap.attack("ABC");
	scavTrap2.takeDamage(10);
	scavTrap2.beRepaired(5);
	scavTrap2.attack("DEF");
	scavTrap.guardGate();

	std::cout << std::endl;
	scavTrap.takeDamage(5);
	std::cout << "[LOG] ScavTrap " << scavTrap.getName() << " has " << scavTrap.getHitPoints()
		<< " hit points left and " << scavTrap.getEnergyPoints() << " energy points left" << std::endl;
		
	scavTrap.beRepaired(10);
	std::cout << "[LOG] ScavTrap " << scavTrap.getName() << " has " << scavTrap.getHitPoints()
		<< " hit points left and " << scavTrap.getEnergyPoints() << " energy points left" << std::endl;

	std::cout << std::endl;
	scavTrap.guardGate();
	return 0;
}