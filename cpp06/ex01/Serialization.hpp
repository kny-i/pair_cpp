
#ifndef PAIR_CPP_SERIALIZATION_HPP
#define PAIR_CPP_SERIALIZATION_HPP

#include <string>
#include <iostream>
#include <stdint.h> // otherwise uintptr_t won't compile with c++98 standard

typedef struct s_data {
	std::string	name;
	size_t		age;
	struct s_data *next;
} t_data;

class Serializer
{
private:

public:
	// Constructors
	Serializer();
	Serializer(const Serializer &src);
	~Serializer();
	Serializer &operator=(const Serializer &src);


	uintptr_t serialize(t_data *ptr);
	t_data *unserialize(uintptr_t raw);

};
#endif //PAIR_CPP_SERIALIZATION_HPP
