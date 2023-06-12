/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 21:25:19 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/04 16:10:49 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <cassert>

int main(void)
{
	//A_Animal	A_Animal("Nameless");	
	Dog			DogA;
	Cat			CatB;
	std::cout<<"DogA is a "<<DogA.getType()<<std::endl;
	std::cout<<"CatB is a "<<CatB.getType()<<std::endl;
	return 0;
}