#include <iostream>
#include <string>

template< typename T >
void iter(T *tab, size_t size, void (*f)(T *elem) = 0)
{
	if (f == NULL)
		return;
	for (size_t i = 0; i < size; i++)
		f(&tab[i]);
	return;	
}

void capitalize(char *c)
{
	if ('a' <= *c && *c <= 'z')
		*c -= 32;
}

template< typename T >
void add(T *c)
{
	try
	{
		if ( char *ptr = dynamic_cast<char *>(c) ) {
			if ('a' <= *ptr && *ptr <= 'z')
				*ptr -= 32;
		}
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	*c -= 32;
}

typedef struct t_iter1
{
	virtual void f(){ std::cout << "iter1\n";}
	char content;
} s_iter1;

typedef struct t_iter2
{
	virtual void f(){ std::cout << "iter2\n";}
	int content;
} s_iter2;

int main(void)
{
	std::string str1 = "Hello c'est chaine 1";
	char str2[] = "Hello c'est chaine 2";
	int tab[20] = {0};

	try
	{
		if (!(tab[120000] = 0))
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
	
	// iter(str1, str1.length(), &capitalize);
	// iter(str2, 20, add);
	std::cout << str2 << std::endl;
	// iter(tab, 20, add);
	for (size_t i = 0; i < 20; i++)
		std::cout << tab[i] << std::endl;

	return 0;
}
