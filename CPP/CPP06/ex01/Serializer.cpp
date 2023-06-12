/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 15:33:18 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/11 15:59:16 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

Serializer::Serializer()
{
	std::cout<<"Serializer default constructor called."<<std::endl;
}

Serializer::Serializer(Serializer &another)
{
	std::cout<<"Serializer copy constructor called."<<std::endl;
	*this = another;
}

Serializer::~Serializer()
{
	std::cout<<"Serializer destructor called."<<std::endl;
}

Data    *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}