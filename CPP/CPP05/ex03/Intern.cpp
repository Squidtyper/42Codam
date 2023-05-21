/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 17:08:58 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:08:14 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

Intern::Intern()
{
	std::cout<<"Intern default constructor called."<<std::endl;
}

Intern::Intern(Intern &another)
{
	*this = another;
	std::cout<<"Intern copy constructor called."<<std::endl;
}

Intern::~Intern()
{
	std::cout<<"Intern destructor called."<<std::endl;
}

AForm	*Intern::makeSCF(std::string target)
{
	return(new ShrubberyCreationForm(false, target));
}

AForm	*Intern::makeRRF(std::string target)
{
	return(new RobotomyRequestForm(false, target));
}

AForm	*Intern::makePPF(std::string target)
{
	return(new PresidentialPardonForm(false, target));
}


AForm	*Intern::makeForm(std::string type, std::string target)
{
	Intern::MF functions[3] = {&Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF};
	std::string levels[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	for (int i = 0; i <3; i++)
	{
		if (type == levels[i])
			return((this->*functions[i])(target));
	}
	std::cout<<"Intern cannot create "<<type<< std::endl;
	return (NULL);
}