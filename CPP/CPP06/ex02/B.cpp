/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   B.cpp                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 18:25:01 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/11 16:08:21 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include <iostream>

B::B()
{
	std::cout<<"B default constructor called."<<std::endl;
}

B::~B()
{
	std::cout<<"B destructor called."<<std::endl;
}