#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain(const Brain& b);
	Brain& operator=(const Brain& b);

	void setIdea(int i, std::string idea);
	std::string getIdea(int i) const;
};

#endif