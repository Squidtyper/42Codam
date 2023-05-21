/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 15:04:30 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/12 18:20:00 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	Form BP("Building Permit", false, 20, 100);
	Form BC("Building Contract", false, 10, 30);
	Bureaucrat Nancy("Nancy", 15);
	
	std::cout<<"Building Permit details:\n"<<BP;
	std::cout<<"Building Contract details:\n"<<BC;
	try
	{
		Nancy.signForm(BP);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Nancy.signForm(BC);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		BC.beSigned(Nancy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	for(int i = 0; i < 5; i++)
		Nancy.incrementGrade();
	try
	{
		Nancy.signForm(BC);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}