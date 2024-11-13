#include "Zombie.hpp"

int	main(void)
{
	Zombie stack_zombie1("Foo1");
	Zombie stack_zombie2("Foo2");
	Zombie stack_zombie3("Foo3");
	Zombie *heap_zombie = newZombie("heap_zombie");

	randomChump("randomChump");
	stack_zombie1.announce();
	stack_zombie2.announce();
	stack_zombie3.announce();
	heap_zombie->announce();

	delete heap_zombie;
}