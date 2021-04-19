#include "easyfind.hpp"

template < typename T >
std::vector<int>::iterator easyfind(T tab, int i) throw (std::string const)
{
	std::vector<int>::iterator trouve = find(tab.begin(), tab.end(), i);
	if(trouve == tab.end()) {
		throw std::string  ("paramètre spécifié introuvable");
	}
	else
		std::cout << i << " a ete trouvee" << std::endl;
	return (trouve);
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	std::vector<int> tab;
	for (size_t i = 0; i < 50; i++) {
		tab.push_back(rand()%100);
		std::cout << tab[i] << std::endl;
	}
	try 
	{
		easyfind(tab, 54);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const std::string& e)
	{
		std::cerr << e << '\n';
	}
	
	return 0;
}
