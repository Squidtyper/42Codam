/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 15:37:44 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:20:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <iostream>

Data::Data(std::string str1, std::string str2, int number)
{
	std::cout<<"Data constructor called."<<std::endl;
	this->_str1 = str1;
	this->_str2 = str2;
	this->_number = number;
}

Data::Data(Data &another)
{
	std::cout<<"Data copy constructor called."<<std::endl;
	this->_str1 = another._str1;
	this->_str2 = another._str2;
	this->_number = another._number;
}

Data::~Data()
{
	std::cout<<"Data destructor called."<<std::endl;
}

Data &Data::operator=(Data &another)
{
	this->_str1 = another._str1;
	this->_str2 = another._str2;
	this->_number = another._number;
	return(*this);
}

std::string	const Data::getStr1() const
{
	return(this->_str1);
}

std::string const Data::getStr2() const
{
	return(this->_str2);
}

int	Data::getNumber() const
{
	return(this->_number);
}
