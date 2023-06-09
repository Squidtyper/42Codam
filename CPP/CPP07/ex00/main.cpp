/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 13:22:54 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 14:47:49 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include <string>

int main(void)
{
	int a = 10;
	int b = 20;
	std::cout<<"before swap: a = "<< a << " b = "<< b << std::endl;
	swap(a, b);
	std::cout<<"after swap: a = " << a << " b = " << b << std::endl;
	std::cout<<"the larger of a and b is: "<< max(a, b)<< std::endl;
	std::cout<<"the smaller of a and b is: "<< min(a, b)<< std::endl;
	std::string c = "A text.";
	std::string d = "Another text.";
	std::cout<<"c and d before swap: c = "<< c << " d = " << d << std::endl;
	swap(c, d);
	std::cout<<"swap a and c: c = "<< c << " d = " << d << std::endl;
	return (0);
}