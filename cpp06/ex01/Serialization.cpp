
#include "Serialization.hpp"

uintptr_t	Serializer::serialize(t_data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data	*Serializer::unserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data *>(raw));
}

Serializer::Serializer()
{
	std::cout << "Serializer Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	std::cout << "Serializer Copy Constructor called" << std::endl;
	*this = src;
}


Serializer::~Serializer()
{
	std::cout << "Serializer Deconstructor called" << std::endl;
}


Serializer &Serializer::operator=(const Serializer &rhs)
{
	std::cout << "Serializer Assignation operator called" << std::endl;
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}
