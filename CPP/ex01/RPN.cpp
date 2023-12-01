/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/17 15:52:02 by lizhang       #+#    #+#                 */
/*   Updated: 2023/08/18 23:29:45 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdlib.h>

void    RPN_error(void)
{
	throw(std::invalid_argument("Error"));
}

bool all_digit(std::string &s)
{
	for (unsigned int i = 0; i < s.length(); i++)
	{
		if (!isdigit(s.at(i)))
			return (false);
	}
	return (true);
}

void	check_input(std::string str)
{
	if (str != "+" && str != "-" && str != "*" && str != "/" && !all_digit(str))
	{
		RPN_error();
	}
}


void    RPN(std::stack<std::string> input)
{
	std::stack<int> numbers;
	std::string av[input.size()];
	size_t len = input.size();
	size_t i = 0;
	while (!input.empty())
	{
		av[i] = input.top();
		input.pop();
		i++;
	}
	i = 0;
	while (i < len)
	{
		check_input(av[i]);
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (all_digit(av[i]))
			numbers.push(atoi(av[i].c_str()));
		else
		{
			if (numbers.empty())
				RPN_error();
			int a = numbers.top();
			numbers.pop();
			if (numbers.empty())
				RPN_error();
			int b= numbers.top();
			numbers.pop();
			int c;
			if (av[i] == "+")
				c = b + a;
			else if (av[i] == "-")
				c = b - a;
			else if(av[i] == "*")
				c = b * a;
			else
				c = b / a;
			numbers.push(c);
		}
		i++;
	}
	if (numbers.size() > 1)
		RPN_error();
	std::cout<<numbers.top()<<std::endl;
}