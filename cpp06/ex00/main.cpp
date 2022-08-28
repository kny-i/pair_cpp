#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) {
		Convert convert(argv[1]);
	} else {
		std::cerr << "Invalid Argument count!" << std::endl;
	}
}
