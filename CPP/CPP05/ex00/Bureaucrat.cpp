/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 14:45:05 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:16:48 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

std::invalid_argument const	Bureaucrat::GradeTooHighException()
{
	return (std::invalid_argument("The given grade is too high. Max level of 1 is allowed."));
}


std::invalid_argument const	Bureaucrat::GradeTooLowException()
{
	return (std::invalid_argument("The given grade is too low. Min level of 150 is allowed."));
}



Bureaucrat::Bureaucrat(): _grade(0)
{
	std::cout<<"Bureacrat default constructor called."<<std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout<<"Bureaucrat constructor called. Name: "<<name<<" Grade: "<<grade<<std::endl;
	if (grade < 1)
		throw this->GradeTooHighException();
	else if (grade > 150)
		throw this->GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat &another)
{
	std::cout<<"Bureaucrat copy constructor called."<<std::endl;
	throw(std::invalid_argument(another.getName()+"Bureaucrat cannot be copied.\n"));
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat "<<this->getName()<<" destructor called."<<std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &another)
{
	this->_grade = another.getGrade();
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int			Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw GradeTooHighException();
	this->_grade++;
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &B)
{
	o<<B.getName()<<", bureaucrat of grade "<<B.getGrade()<<std::endl;
	return (o);
}
