/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 22:09:56 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:40:00 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout<<"Brain default constructor called."<<std::endl;
}

Brain::Brain(Brain const &another)
{
	std::cout<<"Brain copy constructor called."<<std::endl;
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = another._ideas[i];
}

Brain::~Brain()
{
	std::cout<<"Brain destructor called."<<std::endl;
}
	
Brain &Brain::operator=(Brain const &another)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = another._ideas[i];
	return(*this);
}

void	Brain::setIdea(int index, std::string const idea)
{
	if (index < 0 || index > 99)
		std::cout<<"The brain cannot have less than 0 or more than 99 ideas."<<std::endl;
	this->_ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		std::cout<<"The brain cannot have less than 0 or more than 99 ideas."<<std::endl;
	return (this->_ideas[index]);
}