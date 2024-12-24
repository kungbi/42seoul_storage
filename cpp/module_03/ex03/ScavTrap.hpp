#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
private:
	ScavTrap(void);
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap &operator=(const ScavTrap &src);
	~ScavTrap();
	
	void attack(std::string const &target);
	void guardGate(void);
};

#endif