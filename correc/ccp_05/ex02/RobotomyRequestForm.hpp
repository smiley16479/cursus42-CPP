/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsoulier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 12:25:08 by lsoulier          #+#    #+#             */
/*   Updated: 2021/02/08 12:25:09 by lsoulier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <stdexcept>
# include <iostream>
# include <string>
# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm : public Form {
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const & target);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
	std::string const & getTarget() const;
	void execute(Bureaucrat const & executor) const;

private:
	std::string const _target;

};

#endif
