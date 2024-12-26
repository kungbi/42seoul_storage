#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0), _maxHitPoints(10) {
	std::cout << "ClapTrap " << this->_name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
	*this = src;
	std::cout << "ClapTrap " << this->_name << " copy constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->_name << " is destroyed" << std::endl;
}

void ClapTrap::attack(std::string const &target) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return;
	}
	
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", " << "causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	}	
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (this->_energyPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return;
	}

	this->_hitPoints += amount;
	if (this->_maxHitPoints < this->_hitPoints) {
		this->_hitPoints = this->_maxHitPoints;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
}

std::string ClapTrap::getName(void) const {
	return this->_name;
}

int ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}
