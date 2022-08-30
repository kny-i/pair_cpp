#include "Conversion.hpp"

int main(int argc, char **argv)
{
	try {
		if (argc == 2) {
			Convert convert(argv[1]);
		} else {
			std::cerr << "Invalid Argument count!" << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
