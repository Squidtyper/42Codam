/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 19:17:13 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:44:49 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", \
false, 72, 45, "Default")
{
	std::cout<<"RobotomyRequestForm default constructor called."<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(bool allreadySigned, std::string target): \
AForm("RobotomyRequestForm", allreadySigned, 72, 45, target)
{
	std::cout<<"RobotomyRequestForm constructor called."<<std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &another)
{
	std::cout<<"RobotomyRequestForm copy constructor called."<<std::endl;
	*this = another;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"RobotomyRequestForm destructor called."<<std::endl;
}

RobotomyRequestForm   &RobotomyRequestForm::operator=(RobotomyRequestForm &another)
{
	std::cout<<"RobotomyRequestForm cannot be made the same as "<<another.getName()<<std::endl;
	return(*this);
}

std::string		RobotomyRequestForm::getName() const
{
	return(this->_name);
}

bool	RobotomyRequestForm::getState() const
{
	return(this->_signed);
}

int		RobotomyRequestForm::getSignGrade() const
{
	return(this->_signGrade);
}

int		RobotomyRequestForm::getExeGrade() const
{
	return(this->_exeGrade);
}
	
void	RobotomyRequestForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_signGrade && this->getState() == false)
		this->_signed = true;
	else
		throw (std::invalid_argument("RobotomyRequestForm cannot be signed by "+\
		Bureaucrat.getName()+" because the level of the bureaucrat is too low"));
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const{
	if (this->getState() == false)
		throw (std::invalid_argument(this->getName()+
		" cannot be executed because the form is not signed."));
	else if (executor.getGrade() > this->getExeGrade())
		throw(std::invalid_argument(executor.getName()+" cannot execute the form " +\
		"because his/her level is too low."));
	else
	{
		int	random = rand();
		if (random % 2 == 0)
		{
			std::cout<<this->getTarget()<<" has been robotomized."<<std::endl;
		}
		else
			std::cout<<"Robotomy on "<<this->getTarget()<< " has failed."<<std::endl;
	}
}