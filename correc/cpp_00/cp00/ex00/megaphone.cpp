
#include <iostream>
#include <string>
#include <locale>

int     main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
        int i = 1;
        while (argv[i])
        {
            std::string str(argv[i]);
            int j = 0;
            while (argv[i][j])
            {
                std::cout << (char)std::toupper(str[j]);
                j++;
            }
            i++;
        }
		std::cout << std::endl;
	}
	return (0);
}
	