#include <iostream>
#include <fstream>
#include <cstring>

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Usage :\narg_1 -> file name\narg_2 ->"
		"str_to_be_replace\narg_3 -> str_that_replace\n";
		return (-1);
	}
	std::string str0 = av[1]; 
	std::string str1 = av[2]; 
	std::string str2 = av[3];
	std::ifstream ifs(av[1]);
	size_t pos;
	if (ifs.fail())
		return (std::cout << str0 << "does not exit\n", 1);
	std::ofstream ofs(str0 + ".replace");
	while (std::getline(ifs, str0)) {
		if ((pos = str0.find(str1, 0)) != std::string::npos)
			str0.replace(pos, str1.length(), str2);
		ofs << str0 << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}
