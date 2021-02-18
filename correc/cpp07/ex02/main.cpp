/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 10:29:02 by mli               #+#    #+#             */
/*   Updated: 2020/09/11 14:57:10 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
void	displaySize(std::string const name, Array<T> const &array)
{
	std::cout << name << ".size() = " << array.size() << std::endl;
}

template<typename T>
void	displayContent(std::string const name, Array<T> const &array)
{
	const int size = array.size();
	std::cout << name << "'s content :" << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << "- " << name << "[" << i << "] = " << array[i] << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
}

int		main(void)
{
	std::cout << "-----------------------------------------------" << std::endl;
	Array<int>	empty;
	Array<int>	ints(5);

	displaySize("empty", empty);
	displaySize("ints", ints);

	std::cout << "-----------------------------------------------" << std::endl;

	displayContent("empty", empty);
	displayContent("ints", ints);

	ints[0] = 4; ints[1] = 2; ints[2] = 5; ints[3] = 1; ints[4] = 7;
	displayContent("ints", ints);

	try
	{
		std::cout << "Content of ints[5]: " << ints[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Content of ints[5] not accessible"<< std::endl;
	}
	std::cout << "-----------------------------------------------" << std::endl;

	Array<int>	intscpy(ints);
	for (int i = 0; i < intscpy.size(); i++)
		intscpy[i] = 4;
	displayContent("intscpy", intscpy);
	displayContent("ints", ints);

	ints = empty;
	displayContent("ints", ints);

	return (0);
}
