#include "iter.hpp"


class Awesome
{
public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
private:
	int _n;
};

std::ostream & operator<<(std::ostream &o, Awesome &a) {
	o << a.get();
	return o;
}

template <typename T>
void scale_print( T const & x ) { std::cout << x << std::endl; return; }


int main()
{
	{
		std::cout << "[INT CASE]" << std::endl;
		int array[] = {1, 2, 3};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}

	{
		std::cout << std::endl << "[DOUBLE CASE]" << std::endl;
		double array[] = {1.23, 4.56, 7.89};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}

	{
		std::cout << std::endl << "[DOUBLE CASE]" << std::endl;
		char array[] =
				{'4',
				 '2',
				 'o',
				 'T',
				 'k',
				 'y',
				 'o',
				 '!', '\0'};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}
	{
		std::cout << std::endl << "[STRING CASE]" << std::endl;
		std::string array[] = {"NOP", "SATAHARU", "BUNJIRO"};
		::iter(array, sizeof(array) / sizeof(array[0]), print);
	}

	{
		std::cout << "[SCALE TESTCASE]" << std::endl;
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];
		iter( tab2, 5, scale_print );

		iter( tab, 5, scale_print );
	}
}
