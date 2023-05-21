/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:11 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/12 18:15:31 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

std::invalid_argument	Form::GradeTooHighExeption()
{
	return(std::invalid_argument("The given grade is too high. Max level of 1 is allowed."));
}

std::invalid_argument	Form::GradeTooLowException()
{
	return(std::invalid_argument("The given grade is too high. Max level of 150 is allowed."));
}

Form::Form(): _name("Form template"), _signed(false), _signGrade(1), _exeGrade(1)
{
	std::cout<<"Form default constructor called."<<std::endl;
}

Form::Form(std::string name, bool allreadySigned, int signGrade, int exeGrade): \
_name(name), _signed(allreadySigned), _signGrade(signGrade), _exeGrade(exeGrade)
{
	std::cout<<"Form "<<name<<" constructor called."<<std::endl;
	if (signGrade < 1)
		throw this->GradeTooHighExeption();
	if (exeGrade > 150)
		throw this->GradeTooLowException();
}

Form::Form(Form &another): _name(another.getName()), _signed(another._signed), \
_signGrade(another.getSignGrade()), _exeGrade(another.getExeGrade())
{
	std::cout<<"Form copy constructor called."<<std::endl;
}

Form::~Form()
{
	std::cout<<"Form destructor called."<<std::endl;
}

Form	&Form::operator=(Form &another)
{
	throw (std::invalid_argument("Form cannot be made the same because the specs are const"));
	return (another);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool	Form::getState() const
{
	return(this->_signed);
}

int Form::getSignGrade() const
{
	return(this->_signGrade);
}

int Form::getExeGrade() const
{
	return(this->_exeGrade);
}

void	Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_signGrade && this->getState() == false)
		this->_signed = true;
	else
		throw (std::invalid_argument("Form cannot be signed by "+\
		Bureaucrat.getName()+" because the level of the bureaucrat is too low"));
}

std::ostream	&operator<<(std::ostream &os, const Form &a)
{
	os<<"Form name: "<<a.getName()<<std::endl;
	if (a.getState() == false)
		os<<"Is signed: "<<"false"<<std::endl;
	else
		os<<"Is signed: "<<"true"<<std::endl;
	os<<"Level required to sign: "<<a.getSignGrade()<<std::endl;
	os<<"Level required to execute: "<<a.getExeGrade()<<std::endl;
	return (os);
}