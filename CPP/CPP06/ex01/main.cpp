/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 13:36:33 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/11 16:00:49 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main (void)
{
	Data	*data;
	Data	*data2;
	Serializer	tool;
	uintptr_t stored;
	data = new Data("content1", "content2", 42);
	
	stored = tool.serialize(data);
	std::cout<<"data after conversion: "<<stored<<std::endl;
	data2 = tool.deserialize(stored);
	std::cout<<"data2 constains str1: "<<data2->getStr1()<<std::endl;
	std::cout<<"str2: "<<data2->getStr2()<<std::endl;
	std::cout<<"number: "<<data2->getNumber()<<std::endl;

	delete data;
	return (0);
}