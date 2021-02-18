#include "annu.hpp"

Annu::Annu( void ) 
{
	this->msg = {"first name", "last name", "nickname", "login", "postal address", "email address", "phone number", "birthday date", "favoritemeal"}; //, {"underwear color"}, {"darkest secret"}];
	std::cout << "constructor called";
	this->abbon = 0;
}

Annu::~Annu( void )
{
}