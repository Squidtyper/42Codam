/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 18:50:53 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:42:53 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", \
false, 145, 137, "Default")
{
	std::cout<<"ShrubberyCreationForm default constructor called."<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(bool allreadySigned, std::string target): \
AForm("ShrubberyCreationForm", allreadySigned, 145, 137, target)
{
	std::cout<<"ShrubberyCreationForm constructor called."<<std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &another)
{
	std::cout<<"ShrubberyCreationForm copy constructor called."<<std::endl;
	*this = another;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout<<"ShrubberyCreationForm destructor called."<<std::endl;
}

ShrubberyCreationForm   &ShrubberyCreationForm::operator=(ShrubberyCreationForm &another)
{
	std::cout<<"ShrubberyCreationForm cannot be made the same as "<<another.getName()<<std::endl;
	return (*this);
}

std::string		ShrubberyCreationForm::getName() const
{
	return(this->_name);
}

bool	ShrubberyCreationForm::getState() const
{
	return(this->_signed);
}

int		ShrubberyCreationForm::getSignGrade() const
{
	return(this->_signGrade);
}

int		ShrubberyCreationForm::getExeGrade() const
{
	return(this->_exeGrade);
}
	
void	ShrubberyCreationForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_signGrade && this->getState() == false)
		this->_signed = true;
	else
		throw (std::invalid_argument("ShrubberryCreationForm cannot be signed by "+\
		Bureaucrat.getName()+" because the level of the bureaucrat is too low"));
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const{
	if (this->getState() == false)
		throw (std::invalid_argument(this->getName() +
		" cannot be executed because the form is not signed."));
	else if (executor.getGrade() > this->getExeGrade())
		throw(std::invalid_argument(executor.getName() + " cannot execute the form " +\
		"because his/her level is too low."));
	else
	{
		std::ofstream outfile(this->getTarget()+"_shrubbery");
		if (outfile.is_open() <= 0)
		{
			std::cerr<<this->getTarget()+"_shrubbery permission denied"<<std::endl;
			return ;
		}
		outfile<<"  /\\\n /  \\\n/     \\\n--||--";
		outfile.close();
		std::cout<<executor.getName()<<" successfully executed the form on "<<this->getTarget()<<std::endl;
	}
}
