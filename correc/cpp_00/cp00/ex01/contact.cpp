#include "Contact.class.hpp"

Contact::Contact(void){
    info[0] = std::string("First Name");
    info[1] = std::string("Last Name");
    info[2] = std::string("Nickname");
    info[3] = std::string("Login");
    info[4] = std::string("Postal address");
    info[5] = std::string("Email adress");
    info[6] = std::string("Phone number");
    info[7] = std::string("Birthday date");
    info[8] = std::string("Favorite meal");
    info[9] = std::string("Underwear color");
    info[10] = std::string("Darkest secret");
    return;
}

Contact::~Contact(void){
    return;
}

void    Contact::add(){
    /*ajoute les contacts*/
    int i;

    i = 0;
    while (i < 11)
    {
        std::cout << info[i] << " > ";
	    getline(std::cin, info[i]);
        if (info[i].size() == 0)
        {
            std::cout << "\e[91m Tu dois absolument rentrer un champ.\e[0m" << std::endl;
            continue ;
        }
        i++;
    }
	std::cout << "Contact created!" << std::endl;
}

void    Contact::display_char(int i){

        int a;
        int len;
        int b;
        int j;

        a = 10;
        b = 0;
        j = 0;
        std::cout << "             \e[93m|\e[0m        " << i <<"\e[93m|\e[0m";
        while (j < 3)
        {
            len = info[j].size();
            while(len < a){
                std::cout << " ";
                a--;
            }
            while (b < len)
            {
                if (b > 8)
                {
                    std::cout << ".";
                    break;
                }
                std::cout << info[j].at(b);
                b++;
            }
            std::cout << "\e[93m|\e[0m";
            j++;
            a = 10;
            b = 0;
        }
        
        std::cout << std::endl;

}

void    Contact::print_all(void)const{

    for (int i = 0; i < 11 ; i++)
    {
        if (i == 0)
            std::cout << " First Name = " << info[i] << std::endl;
        else if (i == 1)
            std::cout << " Last Name = " << info[i] << std::endl;
        else if (i == 2)
            std::cout << " Nickname = " << info[i] << std::endl;
        else if (i == 3)
            std::cout << " Login = " << info[i] << std::endl;
        else if (i == 4)
            std::cout << " Postal address = " << info[i] << std::endl;
        else if (i == 5)
            std::cout << " Email adress = " << info[i] << std::endl;
        else if (i == 6)
            std::cout << " Phone number = " << info[i] << std::endl;
        else if (i == 7)
            std::cout << " Birthday date = " << info[i] << std::endl;
        else if (i == 8)
            std::cout << " Favorite meal = " << info[i] << std::endl;
        else if (i == 9)
            std::cout << " Underwear color = " << info[i] << std::endl;
        else if (i == 10)
            std::cout << " Darkest secret = " << info[i] << std::endl;
    }

}

