#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
: AForm("Shrubbery Creation", 72, 45, false),  _target( "Anonimous" )
// ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(  std::string target )
: AForm("Shrubbery Creation", 72, 45, false),  _target( target )
// ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("Presidential Pardon", 145, 137)
{
	std::cout << "ShrubberyCreationForm Parameter Constructor called" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) : AForm(src)
{
	std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
	*this = src ;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
	return ;
}

int ShrubberyCreationForm::beSigned( Bureaucrat const & Brct )
{
	std::cout << "Ds le Besigned de ShrubberyCreationForm\n" << std::endl;
	AForm::beSigned(Brct);
	return 0;
}

int ShrubberyCreationForm::execute (Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrd() <= getExecRequiredGrd() && getSignedState()) {
			std::string tmp = _target + "_shrubbery";
			std::ofstream ofs(tmp.c_str());
			ofs << "	           ,@@@@@@@,\n";
			ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
			ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
			ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
			ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
			ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
			ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
			ofs << "       |o|        | |         | |\n";
			ofs << "       |.|        | |         | |\n";
			ofs << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ for " + _target + "\n";
			ofs.close();
			return 1;
		}
		else if (!getSignedState())
			throw std::string ("AForm unsigned, cannot execute");
		else 
			throw AForm::GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
	if (this != &rhs )
		SetSignedState(rhs.getSignedState());
		// AForm::operator=((AForm)rhs);
	return *this;
}

std::ostream & operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "Name AForm is : " << i.getNm() << std::endl;
	o << "Is signed : " << (i.getSignedState() ? "oui": "non") << std::endl;
	o << "Signature required state : " << i.getSignRequiredGrd() << std::endl;
	o << "Execution required state : " << i.getExecRequiredGrd() << std::endl;
	return o;
}