/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A_Animal.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/15 14:47:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/04 15:58:11 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

 #include "A_Animal.hpp"
 #include <iostream>

A_Animal::A_Animal()
{
	std::cout<<"Animal default constructor called."<<std::endl;
	this->_type = "Unspecified";
}

A_Animal::A_Animal(std::string type)
{
	std::cout<<"Animal constructor called."<<std::endl;
	this->_type = type;
}

A_Animal::A_Animal(A_Animal const &another)
{
	std::cout<<"Animal copy constructor called."<<std::endl;
	*this = another;
}

A_Animal::~A_Animal()
{
	std::cout<<"Animal destructor called."<<std::endl;
}

A_Animal &A_Animal::operator=(A_Animal const &another)
{
	this->_type = another._type;
	return (*this);
}

std::string	A_Animal::getType() const
{
	return(this->_type);
}

void	A_Animal::makeSound() const
{
	std::cout<<"The animal makes sound."<<std::endl;
}
