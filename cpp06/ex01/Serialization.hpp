
#ifndef PAIR_CPP_SERIALIZATION_HPP
#define PAIR_CPP_SERIALIZATION_HPP

#include <string>
#include <iostream>
#include <stdint.h> // otherwise uintptr_t won't compile with c++98 standard

typedef struct Data
{
	std::string	name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer
{
private:

public:
	// Constructors
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);


	uintptr_t serialize(Data *ptr);
	Data *unserialize(uintptr_t raw);

};
#endif //PAIR_CPP_SERIALIZATION_HPP
