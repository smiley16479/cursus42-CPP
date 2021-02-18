#ifndef ANNU_CLASS_HPP
#define ANNU_CLASS_HPP
#include <iostream>
#include <string>
#include <array>

class Annu
{
private:
	int abbon;
	std::array<std::string, 11> msg;
public:
	Annu( void );
	~Annu( void );

	int add(std::string s[11]);
};

#endif