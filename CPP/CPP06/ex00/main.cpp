/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 13:36:33 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:17:43 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout<<"Please use one argument."<<std::endl;
		return (0);
	}
	ScalarConverter a;
	a.convert(av[1]);
	return (0);
}