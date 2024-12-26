#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP
# include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(const WrongAnimal& a);
	WrongAnimal& operator=(const WrongAnimal& a);
	
	std::string getType() const;
	void makeSound() const;
};

#endif