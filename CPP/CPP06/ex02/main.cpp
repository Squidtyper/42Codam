/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:57:46 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:48:59 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

static Base	*generate(void)
{
	int number;

	srand(time(NULL));
	number = rand();
	if (number % 3 == 0)
		return(new A());
	else if (number % 3 == 1)
		return(new B());
	else
		return(new C());
}

static void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout<<"This base pointer is class A type."<<std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout<<"This base pointer is class B type."<<std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout<<"This base pointer is class C type."<<std::endl;
	else
		std::cout<<"This base pointer is not one of the A/B/C type."<<std::endl;
}

static void	identify(Base &p)
{
	Base base;
	try
	{
		base = dynamic_cast<A&>(p);
		std::cout<<"This base pointer is class A type."<<std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		base = dynamic_cast<B&>(p);
		std::cout<<"This base pointer is class B type."<<std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		base = dynamic_cast<C&>(p);
		std::cout<<"This base pointer is class C type."<<std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	std::cout<<"This base pointer is not one of the A/B/C type."<<std::endl;
}


int main(void)
{
	Base *b;

	for (int i = 0; i < 2; i++)
	{
		b = generate();
		identify(b);
		identify(*b);
		delete b;
		sleep(1);
	}
	identify(NULL);
	return(0);
}