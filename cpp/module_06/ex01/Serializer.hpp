

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>

typedef struct Data {
	int num;
	std::string s1;
} Data;

class Serializer {
private:
	Serializer(void);
	~Serializer(void);
	Serializer(Serializer const &src);
	Serializer &operator=(Serializer const &rhs);

public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif