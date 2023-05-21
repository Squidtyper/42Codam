/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 15:04:30 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 18:14:42 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

int main()
{
	AForm	*a;
	Intern	b;
	a = b.makeForm("RobotomyRequestForm", "Lisa");
	delete a;
	return 0;
}