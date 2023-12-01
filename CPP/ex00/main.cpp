/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/14 12:56:13 by lizhang       #+#    #+#                 */
/*   Updated: 2023/08/15 15:15:56 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Error: could not open file."<<std::endl;
		return (1);
	}
	std::vector<std::string>	ExchangeFile;
	std::vector<std::string>	RateFile;
	try
	{
		ExchangeFile = read_file(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return(1);
	}
	try
	{
		RateFile = read_file("./cpp_09/data.csv");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return(1);
	}
	ExchangeData ED1(ExchangeFile);
	ExchangeRate ER1(RateFile);
	exchange(ED1, ER1);
	return (0);
}