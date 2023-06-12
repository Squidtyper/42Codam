/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 18:05:48 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:22:05 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal("Cat")
{
	std::cout<<"WrongCat default constructor called."<<std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type)
{
	std::cout<<"WrongCat constructor called."<<std::endl;
}

WrongCat::WrongCat(WrongCat const &another)
{
	std::cout<<"WrongCat copy constructor called."<<std::endl;
	*this = another;
}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called."<<std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &another)
{
	this->_type = another._type;
	return(*this);
}

void	WrongCat::makeSound() const
{
	std::cout<<"The WrongCat says meow meow."<<std::endl;
}