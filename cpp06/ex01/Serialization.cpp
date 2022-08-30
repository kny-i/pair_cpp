
#include "Serialization.hpp"

uintptr_t	Serializer::serialize(t_data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data *>(raw));
}

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &rhs)
{
	*this = rhs;
}

Serializer::~Serializer() {}


Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs) {
		(void)rhs;
	}
	return *this;
}
