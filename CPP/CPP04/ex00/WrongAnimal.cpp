/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 21:50:01 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:18:10 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	std::cout<<"WrongAnimal default constructor called."<<std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(std::string type)
{
	std::cout<<"WrongAnimal constructor called."<<std::endl;
	this->_type = type;
}

WrongAnimal::WrongAnimal(WrongAnimal const &another)
{
	std::cout<<"WrongAnimal copy constructor called."<<std::endl;
	*this = another;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &another)
{
	this->_type = another._type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor called."<<std::endl;
}

void    WrongAnimal::makeSound() const
{
	std::cout<<"The WrongAnimal smakes sound."<<std::endl;
}