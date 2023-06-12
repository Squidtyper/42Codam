/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 21:25:19 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/04 15:18:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void	getleaks()
{
	system("leaks animal");
}

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
 	const Animal* k;
	
	((Dog *)j)->setIdea(0, "The human is my boss.");
	((Cat *)i)->Cat::setIdea(0, "The human is my servant.");
	k = i;
	std::cout<<"The cat thinks: "<<((Cat *)k)->getIdea(0)<<std::endl;
	std::cout<<"The dog thinks: "<<((Dog *)j)->getIdea(0)<<std::endl;
	delete j;
	delete i;

	std::cout<<"-------division line-------"<<std::endl;

	Cat Miloes;
	Miloes.setIdea(0, "I want a snack");
	Cat Jo(Miloes);
	std::cout<<"Jo thinks: "<<Jo.getIdea(0)<<std::endl;
	Miloes.setIdea(0, "I want to pee");
	std::cout<<"Miloes thinks: "<<Miloes.getIdea(0)<<std::endl;
	std::cout<<"Jo thinks: "<<Jo.getIdea(0)<<std::endl;
	atexit(&getleaks);
	return 0;
}