#include <iostream>
#include <string>
#include "iter.hpp"
#include <typeinfo>

template< typename T >
void iter(T *tab, size_t size, void (*f)(T *elem))
{
	if (f == NULL)
		return;
	for (size_t i = 0; i < size; i++)
		f(&tab[i]);
	return;	
}

template< typename T >
void add(T *ptr)
{
	try
	{
		if (*typeid(*ptr).name() == 'i')
			*ptr = 'i';
		else if (*typeid(*ptr).name() == 'c') {
			if ('a' <= *ptr && *ptr <= 'z')
				*ptr -= 32;
		}
		else if (*typeid(*ptr).name() == 'f') 
			*ptr = 'f';
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int main(void)
{
	std::string str1 = "Hello c'est chaine 1";
	char str2[] = "Hello c'est chaine 2";
	int tabi[20] = {0};
	float tabf[20] = {0};

	try
	{
		if (!(tabi[1] = 0))
			throw std::string("error_border");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}

	iter(str2, 20, add);
	std::cout << str2 << std::endl;
	iter(tabi, 20, add);
	iter(tabf, 20, add);
	for (size_t i = 0; i < 20; i++)
		std::cout << tabi[i] << std::endl;
	for (size_t i = 0; i < 20; i++)
		std::cout << tabf[i] << std::endl;
	return 0;
}
