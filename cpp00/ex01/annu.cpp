#include "annu.hpp"

Annu::Annu( void ) 
{
	// this->msg = {"first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal" ,"underwear color", "darkest secret"};
	// std::cout << "constructor called" << std::endl;
	return;
}

Annu::~Annu( void )
{
	// std::cout << "destructor called" << std::endl;
	return ;
}

void add( std::array<std::string, 11> msg, Annu *annu)
{
	for (int i = 0; i < 11; ++i) {
		std::cout << msg[i] << std::endl;
		std::cin  >> annu[Annu::_abbon].user[i];
	}
	++Annu::_abbon;
	return;
}

int	Annu::_abbon = 0;

int main()
{
	Annu annu[8];
	std::string entry;
	std::array<std::string, 11> msg;
	std::array<std::string, 4> tab;
	msg = {"first name", "last name", "nickname", "login", "postal address",
			"email address", "phone number", "birthday date", "favorite meal",
			"underwear color", "darkest secret"};
	tab = {"index", "prénom", "nom de famille", "pseudo\n"};
	while (std::cin >> entry) {
		if (entry == "EXIT") {
			std::cout << "EXIT\n";
			return (0);
		}
		if (entry == "ADD")
		{
			std::cout << "ADD\n";
			add(msg, annu);
		}
		if (entry == "SEARCH") {
			for (int i = 0; i < 4; ++i)
				std::cout << std::setw(10) << tab[i];
			for (int i = 0; i < Annu::_abbon; ++i)	{
				std::cout << std::setw(10) << i;
				std::cout << std::setw(10) << annu[i].user[0];
				std::cout << std::setw(10) << annu[i].user[1];
				std::cout << std::setw(10) << annu[i].user[2];
			}
			std::cout << "\n";
		}
	}
	return (0);
}