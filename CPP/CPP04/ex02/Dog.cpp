/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:17:51 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:37:34 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(): A_Animal("Dog")
{
	std::cout<<"Dog default constructor called."<<std::endl;
	this->_Brain = new Brain();
}

Dog::Dog(std::string type): A_Animal(type)
{
	std::cout<<"Dog constructor called."<<std::endl;
}

Dog::Dog(Dog const &another)
{
	std::cout<<"Dog copy constructor called."<<std::endl;
	this->_type = another._type;
	this->_Brain = new Brain(*another._Brain);
}

Dog &Dog::operator=(Dog const &another)
{
	this->_type = another._type;
	delete this->_Brain;
	this->_Brain = new Brain(*another._Brain);
	return (*this);
}

Dog::~Dog()
{
	std::cout<<"Dog destructor called."<<std::endl;
	delete this->_Brain;
}

void    Dog::makeSound() const
{
	std::cout<<"The dog says: woof woof."<<std::endl;
}

void	Dog::setIdea(int index, std::string idea)
{
	this->_Brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return(this->_Brain->getIdea(index));
}