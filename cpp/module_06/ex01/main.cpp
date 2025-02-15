#include "Serializer.hpp"
#include <iostream>

int main(void) {
	Data data = {42, "Hello, World!"};

	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	std::cout << "Data: " << deserialized->num << " " << deserialized->s1 << std::endl;

	return 0;
}