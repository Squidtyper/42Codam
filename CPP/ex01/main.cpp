/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/17 15:54:22 by lizhang       #+#    #+#                 */
/*   Updated: 2023/08/22 15:34:44 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//when there are consecutive numbers or signs, stack only the numbers not the signs
//see https://commons.wikimedia.org/wiki/File:Reverse_Polish_Notation_Stack_Example.jpg
//only numbers are stored in stack, pop 2 top ones and push the result whenever a sign is met
//only one argument accepted and it's a string

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Error"<<std::endl;
		return(1);
	}
	std::string arg = av[1];
	while (isspace(arg.c_str()[0]))
		arg = arg.substr(1, arg.length() - 1);
	while (isspace(arg.c_str()[arg.length() - 1]))
		arg = arg.substr(0, arg.length() - 1);
	std::stack<std::string> splitstr;
	unsigned int pos = arg.length() - 1;
	while (1)
	{
		std::string str1;
		size_t pos2;
		pos2 = arg.rfind(" ", pos);
		if (pos2!= std::string::npos)
		{
			str1 = arg.substr(pos2 + 1, pos - pos2);
			splitstr.push(str1);
		}
		else
		{
			str1 = arg.substr(0, pos + 1);
			splitstr.push(str1);
			break ;
		}
		pos2--;
		pos = pos2;
	}
	try
	{
		RPN(splitstr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}