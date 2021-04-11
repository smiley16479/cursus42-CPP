#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat gratteur("gratteur", 2); // remettre un grade correct...
		gratteur.incGrd();
		std::cout << gratteur << std::endl;
		Form form, form_2("202-46B", 2, 2, true);
		std::cout << form << std::endl;
		std::cout << form_2 << std::endl;
		Form form3;
		form3 = form_2;
		std::cout << form3 << std::endl;
		gratteur.signForm(form_2);
	}
	catch(std::exception &e)
	{
		return 1;
	}
	catch(std::string &str)
	{
		std::cout << str << std::endl;
		return 1;
	}
	return 0;
}