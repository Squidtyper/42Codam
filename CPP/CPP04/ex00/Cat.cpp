/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:24:10 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:09:22 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat():Animal("Cat")
{
	std::cout<<"Cat default constructor called."<<std::endl;
}

Cat::Cat(std::string type)
{
	std::cout<<"Cat constructor called."<<std::endl;
	this->_type = type;
}

Cat::Cat(Cat const &another)
{
	std::cout<<"Cat copy constructor called."<<std::endl;
	*this = another;
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called."<<std::endl;
}

Cat &Cat::operator=(Cat const &another)
{
	this->_type = another._type;
	return(*this);
}

void	Cat::makeSound() const
{
	std::cout<<"The cat says meow meow."<<std::endl;
}