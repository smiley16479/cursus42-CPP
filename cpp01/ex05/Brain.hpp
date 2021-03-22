#ifndef BRAIN_CLASS_HPP
#define BRAIN_CLASS_HPP
#include <iostream>
#include <sstream>

class Brain
{
private:
	int _Uptime;
	int _Task;
	int _Load_average;

public:
	Brain(int Uptime = 0, int Task = 0, int Load_average = 0);
	~Brain( void );

	std::string identifier( void ) const;
};

#endif