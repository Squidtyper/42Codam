/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 17:33:11 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/26 16:31:01 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <iterator>
#include <vector>

int main(void)
{
	Span A(3);
	Span B(A);
	try
	{
		A.addNumber(-1);
		A.addNumber(2);
		A.addNumber(20);
		A.addNumber(15);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout<<"Shortest span of A: "<<A.shortestSpan()<<std::endl;
	std::cout<<"Longest span of A: "<<A.longestSpan()<<std::endl;
	B.addNumber(5);
	try
	{
		B.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Span C(15000);
	C.randFill(-100, 200);
	std::cout<<"shortest span C: "<<C.shortestSpan()<<std::endl;
	std::cout<<"longest span C: "<<C.longestSpan()<<std::endl;
	Span D(10);
	int i = 1234;
	for(unsigned int j = 0; j < 10; j++)
	{
		D.addNumber(i);
		i++;
	}
	i = 0;
	for(Span::iterator it = D.begin(); it < D.end(); it++)
	{
		std::cout<<D[i]<<std::endl;
		i++;
	}
	return (0);
}