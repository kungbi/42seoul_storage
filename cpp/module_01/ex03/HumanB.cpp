#include "HumanB.hpp"


HumanB::HumanB(std::string name) 
{
	this->name = name;
	this->weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon){ this->weapon = &weapon;}

void HumanB::attack(void) const
{
	std::string nowWeapon;
	if (this->weapon == NULL)
		nowWeapon = "hit hand";
	else
		nowWeapon = this->weapon->getType();

    std::cout << this->name << " attacks with a " << nowWeapon << std::endl;
}