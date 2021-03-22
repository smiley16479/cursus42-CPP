#ifndef PONY_CLASS_HPP
#define PONY_CLASS_HPP
#include <iostream>
#include <string>
#include <array>
#include <iomanip>

class Pony
{
private:
	int size;
	std::string color;
	// std::array<std::string, 11> friends;

public:
	Pony(int size, std::string color, std::string name);
	~Pony( void );

	std::string name;
	static int _instance_nb;
	int trote( void ) const;
	int galop( void ) const;
	int secoue_ma_criniere( std::string name ) const;
};

#endif