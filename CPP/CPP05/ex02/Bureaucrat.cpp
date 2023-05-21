/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 14:45:05 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:19:23 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

std::invalid_argument const	Bureaucrat::GradeTooHighException()
{
	this->_grade = 1;
	return (std::invalid_argument("The given grade is too high. Max level of 1 is given."));
}


std::invalid_argument const	Bureaucrat::GradeTooLowException()
{
	this->_grade = 150;
	return (std::invalid_argument("The given grade is too low. Min level of 150 is given."));
}

Bureaucrat::Bureaucrat()
{
	std::cout<<"Bureacrat default constructor called."<<std::endl;
	this->_grade = 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	std::cout<<"Bureaucrat constructor called. Name: "<<name<<" Grade: "<<grade<<std::endl;
	if (grade < 1)
		throw this->GradeTooHighException();
	else if (grade > 150)
		throw this->GradeTooLowException();
	else
	{
		this->_name = name;
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat &another)
{
	std::cout<<"Bureaucrat copy constructor called."<<std::endl;
	this->_grade = another._grade;
	this->_name = another._name;
}

Bureaucrat::~Bureaucrat()
{
	std::cout<<"Bureaucrat destructor called."<<std::endl;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat &another)
{
	this->_grade = another._grade;
	this->_name = another._name;
	return (*this);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
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

void	Bureaucrat::signForm(AForm &a)
{
	if (this->getGrade() <= a.getSignGrade() && a.getState() == false)
		std::cout<<this->getName()<<" signed "<<a.getName()<<std::endl;
	else
		std::cout<<this->getName()<<" tried to sign " <<a.getName()<<std::endl;
	a.beSigned(*this);
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &B)
{
	o<<B.getName()<<", bureaucrat of grade "<<B.getGrade()<<std::endl;
	return (o);
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (form.getState() == false)
		throw (std::invalid_argument(form.getName()+
		" cannot be executed because the form is not signed."));
	else if (this->getGrade() > form.getExeGrade())
		throw(std::invalid_argument(this->getName()+" cannot execute the form " +\
		"because his/her level is too low."));
	else
	{
		form.execute(*this);
		std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
	}
}