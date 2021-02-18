#include "Contact.class.hpp"
#include "contact.cpp"

void	search(Contact book[8], int nb_contact){
	int index;
	int i;

	i = 0;
	if (nb_contact == 0)
	{
		std::cout << "Annuaire vide" << std::endl;
		return;
	}
	std::cout << "\e[93m             |    Index|First Name| Last Name|  Nickname|  \e[0m" << std::endl;
	while (i < nb_contact)
	{
		book[i].display_char(i + 1);
		i++;
	}
	while(1)
	{
		std::cout << "\n\e[93m              Rentre l'index que tu veux ou 0 pour sortir.\e[0m" << std::endl << " - ";
		std::cin >> index;
		if (std::cin.fail() || index > nb_contact || index < 0)
		{
			std::cout << "\e[91m              Wrong index\e[0m" << std::endl;
			std::cout << std::endl;
            std::cin.clear();
		}
		else
        {
        	if (index == 0)
            {
                std::cout << std::endl;
                std::cin.clear();
				std::cin.ignore(10000, '\n');
                return;
            }
			else
			{
				book[index - 1].print_all();
			}
		}
	}
}

int main()
{
	std::string input;
	Contact book[8];
	int nb_contact;

	nb_contact = 0;
	while (1)
	{
		std::cout << "> ADD, SEARCH or EXIT ?" << std::endl << " - ";
		std::getline(std::cin, input);
		if(input == "ADD"){
			if (nb_contact < 8)
			{
				book[nb_contact].add();
				nb_contact++;
			}
			else
				std::cout << "Limite de contacte atteint" << std::endl;
		}
		else if (input == "SEARCH"){
			search(book, nb_contact);
			//fflush(stdin);
		}
		else if (input == "EXIT"){
			return (0);
		}
		else
			std::cout << "command error : please enter ADD, EXIT or SEARCH." << std::endl;
	}
	
	return 0;
}