#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) {
		Convert convert(argv[1]);
		convert.printValues();
	} else {
		std::cerr << "Invalid Argument count!" << std::endl;
	}
}
