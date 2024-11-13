#include "Zombie.hpp"


Zombie::Zombie(std::string name) 
{
	if (name.empty())
		this->_name = "default_name";
	else
		this->_name = name;
}

Zombie::~Zombie()
{
	std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name <<  " BraiiiiiiinnnzzzZ..." << std::endl;
}