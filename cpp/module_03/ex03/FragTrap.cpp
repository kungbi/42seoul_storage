#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_maxHitPoints = 100;
	std::cout << "FragTrap " << this->getName() << " is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src): ClapTrap(src) {
	this->_name = src.getName();
	this->_hitPoints = src.getHitPoints();
	this->_energyPoints = src.getEnergyPoints();
	this->_attackDamage = src.getAttackDamage();
	
	std::cout << "FragTrap " << this->getName() << " copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->getName() << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->getName() << " has no energy points left!" << std::endl;
		return;
	}
	if (this->_hitPoints <= 0) {
		std::cout << "FragTrap " << this->getName() << " is already dead!" << std::endl;
		return;
	}
	
	this->_energyPoints--;
	std::cout << "FragTrap " << this->getName() << " high fives guys!" << std::endl;
}