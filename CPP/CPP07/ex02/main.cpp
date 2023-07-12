/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 13:57:35 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 16:11:52 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include "Array.ipp"
#include <iostream>

int main(void)
{
	Array<int> A;
	std::cout<<"size of A is: "<<A.size()<<std::endl;
	Array<int> B(2);
	std::cout<<"size of B is: "<<B.size()<<std::endl;
	Array<int> C(A);
	try
	{
		std::cout<<&B[3]<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout<<&B[-1]<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	B[0] = 100;
	std::cout<<"B[0] value: "<<B[0]<<std::endl;
	A = B;
	std::cout<<"size of A is: "<<A.size()<<std::endl;
	std::cout<<&B[1]<<std::endl;
	return (0);
}