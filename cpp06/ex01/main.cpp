#include "Serialization.hpp"


void print(t_data data) {
	std::cout << std::endl << "__________________" << std::endl;
	std::cout << "\naddress: " << &data <<
	"\nname: " << data.name <<
	"\nage: " << data.age <<
	"\naddress next: " << data.next <<
	std::endl;
}

int main()
{
	t_data ptr2;

	ptr2.name = "Nop";
	ptr2.age = 42;
	ptr2.next = NULL;

	t_data ptr;
	ptr.name = "AKO";
	ptr.age = 42;
	ptr.next = &ptr2;
	std::cout << "<<<Here is the original structs>>>";
	print(ptr);
	print(ptr2);


	Serializer a;

	t_data *reserialized_struct = a.deserialize(a.serialize(&ptr));

	t_data *reserialized_struct2 = a.deserialize(a.serialize(&ptr2));
	std::cout << std::endl << "<<<Here is the reserialized structs>>>";
	print(*reserialized_struct);
	print(*reserialized_struct2);
}
