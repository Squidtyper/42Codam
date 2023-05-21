/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:13:27 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:41:26 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", \
false, 25, 5, "Default")
{
	std::cout<<"PresidentialPardonForm default constructor called."<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(bool allreadySigned, std::string target): AForm(\
"PresidentialPardonForm", allreadySigned, 25, 5, target)
{
	std::cout<<"PresidentialPardonForm constructor called."<<std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &another)
{
	std::cout<<"PresidentialPardonForm copy constructor called."<<std::endl;
	*this = another;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"PresidentialPardonForm destructor called."<<std::endl;
}

PresidentialPardonForm   &PresidentialPardonForm::operator=(PresidentialPardonForm &another)
{
	std::cout<<"PreseidentialPardonForm cannot be made the same as "<<another.getName()<<std::endl;
	return(*this);
}

std::string		PresidentialPardonForm::getName() const
{
	return(this->_name);
}

bool	PresidentialPardonForm::getState() const
{
	return(this->_signed);
}

int		PresidentialPardonForm::getSignGrade() const
{
	return(this->_signGrade);
}

int		PresidentialPardonForm::getExeGrade() const
{
	return(this->_exeGrade);
}
	
void	PresidentialPardonForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_signGrade && this->getState() == false)
		this->_signed = true;
	else
		throw (std::invalid_argument("PresidentialPardonForm cannot be signed by "+\
		Bureaucrat.getName()+" because the level of the bureaucrat is too low"));
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getState() == false)
		throw (std::invalid_argument(this->getName()+
		" cannot be executed because the form is not signed."));
	else if (executor.getGrade() > this->getExeGrade())
		throw(std::invalid_argument(executor.getName()+" cannot execute the form " +\
		"because his/her level is too low."));
	else
	{
		std::cout<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox."<<std::endl;
	}
}