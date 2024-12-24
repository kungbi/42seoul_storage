#include "FragTrap.hpp"

int main(void) {
	FragTrap fragTrap("John");
	FragTrap fragTrap2(fragTrap);

	fragTrap.attack("enemy");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();

	return 0;
}