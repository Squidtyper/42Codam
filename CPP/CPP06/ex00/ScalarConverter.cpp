/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 18:30:12 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:17:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>

ScalarConverter::ScalarConverter()
{
    std::cout<<"ScalarConverter default constructor called."<<std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout<<"ScalarConverter destructor called."<<std::endl;
}
		
char ScalarConverter::toChar(std::string input)
{
	int	a;
	if (input.length() == 1 && isprint(input.c_str()[0]) == 1)
		return(static_cast<char>(input.c_str()[0]));
	if (input.length() > 0 && \
	input.find_first_not_of("-+0123456789.f") != (size_t)(-1))
		throw (std::invalid_argument("impossible"));
	try
	{
		a = std::stoi(input);
	}
	catch(const std::exception& e)
	{
		throw (std::invalid_argument("impossible"));
	}
	if (isascii(a) != 1)
		throw (std::invalid_argument("impossible"));
	if (isprint(a) != 1)
		throw (std::invalid_argument("Non displayable"));
	return (static_cast<char>(a));
}

int ScalarConverter::toInt(std::string input)
{
	int i;

	if (input.find_first_not_of("-+0123456789.f") != (size_t)(-1))
	{
		throw(std::invalid_argument("impossible"));
	}
	try
	{
		i = std::stoi(input);
		return(static_cast<int>(i));
	}
	catch(const std::exception& e)
	{
		throw (std::invalid_argument("impossible"));
	}
	throw (std::invalid_argument("impossible"));
}

float ScalarConverter::toFloat(std::string input)
{
	float value;

	if (input == "inf" || input == "+inf" ||\
	input == "inff" || input == "-inff")
		return (static_cast<float>(INFINITY));
	if (input == "-inf")
		return (static_cast<float>(-INFINITY));
	if (input == "nan" || input == "nanf")
		return (static_cast<float>(NAN));
	if (input.find_first_not_of("-+0123456789f.") != (size_t)(-1) \
	|| std::count(input.begin(),input.end(), '.') > 1 ||
	std::count(input.begin(),input.end(), 'f') > 1)
		throw(std::invalid_argument("impossible"));
	try
	{
		value = std::stof(input);
		return(static_cast<float>(value));
	}
	catch(const std::exception& e)
	{
		throw (std::invalid_argument("impossible"));
	}
	throw (std::invalid_argument("impossible"));
}

double	ScalarConverter::toDouble(std::string input)
{
	double f;

	if (input == "inf" || input == "+inf" || \
	input == "inff" || input == "-inff")
		return (static_cast<double>(INFINITY));
	if (input == "-inf")
		return (static_cast<double>(-INFINITY));
	if (input == "nan" || input == "nanf")
		return (static_cast<double>(NAN));
	if (input.find_first_not_of("-+0123456789.f") != (size_t)(-1) \
	|| std::count(input.begin(),input.end(), '.') > 1 || \
	std::count(input.begin(),input.end(), 'f') > 1)
		throw(std::invalid_argument("impossible"));
	try
	{
		f = std::stof(input);
		return(static_cast<double>(f));
	}
	catch(const std::exception& e)
	{
		throw (std::invalid_argument("impossible"));
	}
	throw (std::invalid_argument("impossible"));
}



void	ScalarConverter::convert(std::string input)
{
	try
	{
		std::cout<<"char: ";
		toChar(input);
		std::cout<<"'"<<toChar(input)<<"'"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout<<"int: "<<toInt(input)<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout<<"float: "<<std::fixed<<std::setprecision(1)<<toFloat(input);
		std::cout<<"f"<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout<<"double: "<<std::fixed<<std::setprecision(1)<<toDouble(input)<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}