/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   C.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 18:26:27 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/08 18:27:12 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include <iostream>

C::C()
{
	std::cout<<"C default constructor called."<<std::endl;
}

C::~C()
{
	std::cout<<"C destructor called."<<std::endl;
}