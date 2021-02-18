#include <iostream>
#include <ctype.h>

int main(int ac, char **av)
{
	int i;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (--ac && (*++av) && !(i = 0))
		while((*av)[i])
			std::cout << (char)toupper((*av)[i++]);
	std::cout << std::endl;
	return (0);
}
