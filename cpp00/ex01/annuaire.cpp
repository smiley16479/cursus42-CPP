#include "annuaire.hpp"

// Annu::Annu( void ) 
// {
// 	// this->msg = {"first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favorite meal" ,"underwear color", "darkest secret"};
// 	// std::cout << "constructor called" << std::endl;
// 	return;
// }

// Annu::~Annu( void )
// {
// 	// std::cout << "destructor called" << std::endl;
// 	return ;
// }

void add(Annu *annu)
{
	std::array<std::string, 11> msg = {"first name", "last name", "nickname",
		 "login", "postal address", "email address", "phone number",
		 "birthday date", "favorite meal", "underwear color", "darkest secret"};
	if (Annu::_abbon < 8 && ++Annu::_abbon)
		for (int i = 0; i < 11; ++i) {
			std::cout << msg[i] << std::endl;
			std::getline(std::cin, annu[Annu::_abbon - 1].user[i]);
		}		
	else
		std::cout << "Sorry, phonebook already full" << std::endl;
	return;
}

void print_info(Annu annu)
{
	std::array<std::string, 11> msg = {"first name", "last name", "nickname",
		 "login", "postal address", "email address", "phone number",
		 "birthday date", "favorite meal", "underwear color", "darkest secret"};
	for (int i = 0; i < 11; ++i)
		std::cout << msg[i] + " => " + annu.user[i] << std::endl;
	return;
}

void print_usage(void)
{
	std::cout << "use ADD SEARCH or EXIT\n";
	return;
}

void search(Annu annu[8])
{
	std::string str = {"|     index|first name| last name|  nickname|\n"};
	int nb;
	char c;

	std::cout << YELLOW << str;
	for (int i = 0; i < Annu::_abbon; ++i)	{
		std::cout << YELLOW << "|" << RESET << std::setw(10) << i + 1;
		for (int j = 0; j < 3; ++j)
			if (annu[i].user[j].length() > 10)
				std::cout << YELLOW << "|" << RESET << annu[i].user[j].substr(0, 9) << ".";
			else
				std::cout << YELLOW << "|" << RESET << std::setw(10) << annu[i].user[j];
		std::cout << YELLOW << "|" << RESET << std::endl;
	}
	std::cout << RESET;
	std::cout << "\nEnter index number to view full contact's info\n";
	std::cin >> nb;
	if (std::cin.fail() && std::cout << "Not a valid number. Please reenter:\n")
		while (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
			std::cin >> nb;
		}
	while (std::cin.get(c) && c != '\n') { // remove additional char until '\n'
		if (!std::isspace(c)) {
			std::cerr << "ERROR unexpected character '" << c << "' found\n";
			exit(EXIT_FAILURE);
		}
	}
	if (0 < nb && nb <= Annu::_abbon && !std::cin.fail())
		print_info(annu[nb - 1]);
	else
		std::cout << "Invalid index\n";
}

int get_entry(std::string *entry)
{
	print_usage();
	std::cout << " - ";
	if(!std::getline(std::cin, *entry))
		std::cin.clear();
	return (1);
}

int	Annu::_abbon = 0;

int main()
{
	Annu annu[8];
	std::string entry;

	while (get_entry(&entry)) {
		if (entry == "ADD")
			add(annu);
		else if (entry == "SEARCH")
			search(annu);
		else if (entry == "EXIT") {
			std::cout << "EXITING... BYE !\n";
			return (0);
		}
		else
			std::cout << "unkown command\n";
	}
	return (0);
}