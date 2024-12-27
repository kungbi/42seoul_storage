
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
private:
	ClapTrap(void);
protected:
	std::string _name;
	int _hitPoints;
	int _energyPoints;
	int _attackDamage;
	int _maxHitPoints;
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap &operator=(const ClapTrap &src);
	~ClapTrap();
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string getName(void) const;
	int getHitPoints(void) const;
	int getEnergyPoints(void) const;
	int getAttackDamage(void) const;
};

#endif