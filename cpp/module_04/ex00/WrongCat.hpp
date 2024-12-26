#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP
# include <iostream>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& c);
	WrongCat& operator=(const WrongCat& c);
	
	void makeSound() const;
};

#endif