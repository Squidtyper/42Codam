/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:58:27 by lizhang       #+#    #+#                 */
/*   Updated: 2023/01/14 19:06:11 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
    std::string	line;
	PhoneBook PB;

    PB.init();
	while (true)
	{
		getline(std::cin, line, '\n');
		if (strcmp(line.c_str(), "ADD") == 0)
			PB.add();
		else if (strcmp(line.c_str(), "SEARCH") == 0)
			PB.search();
		else if (strcmp(line.c_str(), "EXIT") == 0)
		{
			break ;
		}
	}
	return(0);
}