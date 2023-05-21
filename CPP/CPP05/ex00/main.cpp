/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 15:04:30 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/12 17:49:14 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat Ayda("Ayda", -1);
		std::cout<<Ayda.getName()<<" is successfully created."<<std::endl;
    }
    catch (const std::invalid_argument & e)
    {
        std::cerr << e.what() << std::endl;
    }
	Bureaucrat Belen("Belen", 1);
	std::cout<<Belen.getName()<<" is successfully created."<<std::endl;
	try
	{
		Belen.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<Belen.getName()<<" after decrement has grade: "<<Belen.getGrade()<<std::endl;

	Bureaucrat Cecilia("Cecilia", 1);
	std::cout<<Cecilia.getName()<<" is successfully created."<<std::endl;
	try
	{
		Cecilia.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<Cecilia.getName()<<" after increment has grade: "<<Cecilia.getGrade()<<std::endl;
    return 0;
}