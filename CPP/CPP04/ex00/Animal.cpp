/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 14:47:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 21:45:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "Animal.hpp"
 #include <iostream>

Animal::Animal()
{
	std::cout<<"Animal default constructor called."<<std::endl;
	this->_type = "Unspecified";
}

Animal::Animal(std::string type)
{
	std::cout<<"Animal constructor called."<<std::endl;
	this->_type = type;
}

Animal::Animal(Animal const &another)
{
	std::cout<<"Animal copy constructor called."<<std::endl;
	*this = another;
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called."<<std::endl;
}

Animal &Animal::operator=(Animal const &another)
{
	this->_type = another._type;
	return (*this);
}

void	Animal::setType(std::string type)
{
	this->_type = type;
	std::cout<<"The type of the animal is set to "<<this->_type<<std::endl;
}

std::string	Animal::getType() const
{
	return(this->_type);
}

void	Animal::makeSound() const
{
	std::cout<<"The animal makes sound."<<std::endl;
}