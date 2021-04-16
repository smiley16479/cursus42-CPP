#include "Array.tpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	Array<int> arrayI(5);
	Array<float> arrayf(3);
	arrayI[0] = 0;
	arrayI[1] = 1;
	arrayI[2] = 2;
	try
	{
		std::cout <<  static_cast<float>(arrayf[2]);
		arrayf.show();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	// std::cout << f;



	return 0;
}
