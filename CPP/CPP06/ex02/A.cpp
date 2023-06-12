/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 18:08:08 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:21:19 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include <iostream>

A::A()
{
	std::cout<<"A default constructor called."<<std::endl;
}

A::~A()
{
	std::cout<<"A destructor called."<<std::endl;
}