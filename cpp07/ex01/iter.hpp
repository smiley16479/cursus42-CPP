#include <iostream>
#include <string>

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

template< typename T >
void iter(T *tab, size_t size, void (*f)(T *elem) = 0);

void capitalize(char *c);

template< typename T >
void add(T *c);