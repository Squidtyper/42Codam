/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:11 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 18:08:41 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

std::invalid_argument	AForm::GradeTooHighExeption()
{
	return(std::invalid_argument("The given grade is too high. Max level of 1 is allowed."));
}

std::invalid_argument	AForm::GradeTooLowException()
{
	return(std::invalid_argument("The given grade is too high. Max level of 150 is allowed."));
}

AForm::AForm(): _name("Form template"), _target("Default"), _signed(false), _signGrade(1), _exeGrade(1)
{
	std::cout<<"Form default constructor called."<<std::endl;
}

AForm::AForm(std::string name, bool allreadySigned, int signGrade, int exeGrade, std::string target): \
_name(name), _target(target), _signed(allreadySigned), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout<<"Form "<<name<<" constructor called with target: "<<target<<std::endl;
	if (signGrade < 1)
		throw this->GradeTooHighExeption();
	if (exeGrade > 150)
		throw this->GradeTooLowException();
}

AForm::AForm(AForm &another): _name(another.getName()), _signed(another._signed), \
_signGrade(another.getSignGrade()), _exeGrade(another.getExeGrade())
{
	std::cout<<"Form copy constructor called."<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"Form destructor called."<<std::endl;
}

AForm	&AForm::operator=(AForm &another)
{
	throw (std::invalid_argument("Form cannot be made the same because the specs are const"));
	return (another);
}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string	AForm::getTarget() const
{
	return(this->_target);
}

bool	AForm::getState() const
{
	return(this->_signed);
}

int AForm::getSignGrade() const
{
	return(this->_signGrade);
}

int AForm::getExeGrade() const
{
	return(this->_exeGrade);
}

void	AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_signGrade && this->getState() == false)
		this->_signed = true;
	else
		throw (std::invalid_argument("Form cannot be signed by "+\
		Bureaucrat.getName()+" because the level of the bureaucrat is too low"));
}

void	AForm::execute(Bureaucrat const &executor) const
{
	std::cout<<executor.getName()<<" has been asked to execute "<<this->getName()\
	<<" on "<<this->_target<<std::endl;
}

std::ostream	&operator<<(std::ostream &os, const AForm &a)
{
	os<<"Form name: "<<a.getName()<<std::endl;
	os<<"Form target: "<<a.getTarget()<<std::endl;
	if (a.getState() == false)
		os<<"Is signed: "<<"false"<<std::endl;
	else
		os<<"Is signed: "<<"true"<<std::endl;
	os<<"Level required to sign: "<<a.getSignGrade()<<std::endl;
	os<<"Level required to execute: "<<a.getExeGrade()<<std::endl;
	return (os);
}