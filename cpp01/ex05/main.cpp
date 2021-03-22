#include "Human.hpp"

int main(void)
{
	Human bob;
	std::cout << bob.identifier() << std::endl;
	std::cout << bob.getBrain().identifier() << std::endl;
	return(0);
}