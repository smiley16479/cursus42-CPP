#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void identify_from_pointer(Base * p)
{
	if ( A *a = dynamic_cast<A*>(p) )
		std::cout << "A\n";
	else if ( B *b = dynamic_cast<B*>(p) )
		std::cout << "B\n";
	else if ( C *c = dynamic_cast<C*>(p) )
		std::cout << "C\n";
	else
		std::cout << "Other class than A,B or C\n";
}

void identify_from_reference(Base & p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch(const std::exception& e){}
	std::cout << "Other class than A,B or C\n";
}

Base * generate(void)
{
	int i = rand() % 3;
	if ( i == 0 )
		return (new A);
	else if ( i == 1 )
		return (new B);
	else
		return (new C);
}

int main(void){
	srand (time(NULL));
	
	Base * b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);
	delete b;
	return 0;
}