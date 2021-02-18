/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 13:37:10 by mli               #+#    #+#             */
/*   Updated: 2020/09/11 14:43:26 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

# include <iostream>
# include <string>
# include <exception>

template<typename T>
class Array {
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		virtual ~Array(void);

		Array	&operator=(Array const &rhs);
		T		&operator[](int rhs) const;

		int		size(void) const;
	protected:
	private:
		T		*content;
		int		_size;
};

template<typename T>
Array<T>::Array(void) : content(NULL), _size(0) {
//	std::cout << "Default Constructor Called" << std::endl;
	return ;
}

template<typename T>
Array<T>::Array(unsigned int n) : content(new T[n]()), _size(n) {
//	std::cout << "Constructor Called" << std::endl;
	return ;
}

template<typename T>
Array<T>::Array(Array const &src) : content(NULL) {
	*this = src;
}

template<typename T>
Array<T>::~Array(void) {
//	std::cout << "Destructor Called" << std::endl;
	delete [] this->content;
	return ;
}

template<typename T>
Array<T>	&Array<T>::operator=(Array const &rhs) {
	if (this == &rhs)
		return (*this);
	delete [] this->content;
	this->_size = rhs._size;
	this->content = (rhs._size != 0 ? new T[rhs._size] : NULL);
	for (int i = 0; i < rhs._size; i++)
		this->content[i] = rhs.content[i];
	return (*this);
}

template<typename T>
int		Array<T>::size(void) const { return (this->_size); }

template<typename T>
T		&Array<T>::operator[](int rhs) const {
	if (rhs < 0 || rhs >= this->_size)
		throw std::exception();
	return (this->content[rhs]);
}

#endif // *********************************************** ARRAY_CLASS_HPP end //
