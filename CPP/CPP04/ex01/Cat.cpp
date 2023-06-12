/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:24:10 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:25:05 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal("Cat")
{
	std::cout<<"Cat default constructor called."<<std::endl;
	this->_Brain = new Brain;
}

Cat::Cat(std::string type): Animal(type)
{
	std::cout<<"Cat constructor called."<<std::endl;
	this->_Brain = new Brain;
}

Cat::Cat(Cat const &another)
{
	std::cout<<"Cat copy constructor called."<<std::endl;
	this->_type = another._type;
	this->_Brain = new Brain(*another._Brain);
}

Cat::~Cat()
{
	std::cout<<"Cat destructor called."<<std::endl;
	delete this->_Brain;
}

Cat &Cat::operator=(Cat const &another)
{
	this->_type = another._type;
	delete this->_Brain;
	this->_Brain = new Brain(*another._Brain);
	return(*this);
}

void	Cat::makeSound() const
{
	std::cout<<"The cat says meow meow."<<std::endl;
}

void	Cat::setIdea(int index, std::string idea)
{
	this->_Brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	return(this->_Brain->getIdea(index));
}