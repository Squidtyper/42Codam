/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:17:51 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:19:46 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal("Dog")
{
	std::cout<<"Dog default constructor called."<<std::endl;
}

Dog::Dog(std::string type): Animal(type)
{
	std::cout<<"Dog constructor called."<<std::endl;
}

Dog::Dog(Dog const &another)
{
	std::cout<<"Dog copy constructor called."<<std::endl;
	*this = another;
}

Dog &Dog::operator=(Dog const &another)
{
	this->_type = another._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called."<<std::endl;
}

void    Dog::makeSound() const
{
	std::cout<<"The dog says: woof woof."<<std::endl;
}