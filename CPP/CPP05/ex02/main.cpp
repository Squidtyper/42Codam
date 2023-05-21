/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 15:04:30 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:44:37 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat	Nancy("Nancy", 35);
	Bureaucrat	Billy("Billy", 1);

	RobotomyRequestForm		RRF(false, "Jamie");
	PresidentialPardonForm	PPF(false, "Jamie");
	ShrubberyCreationForm	SCF(false, "Jamie");

	std::cout<<"------test part------"<<std::endl;
	try
	{
		Nancy.signForm(SCF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		SCF.execute(Nancy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Billy.signForm(PPF);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PPF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		PPF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	RRF.beSigned(Billy);
	try
	{
		RRF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RRF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RRF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RRF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		RRF.execute(Billy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<"------test end------"<<std::endl;
	return 0;
}