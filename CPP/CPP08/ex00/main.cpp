/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/03 16:21:58 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/12 16:28:08 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

//a container can be : array(class), vector, deque, forward_list, list
//set, multiset, map, multimap

int main(void)
{
	int					A1[] = {1, 2, 5, 10, -3};
	std::vector<int>	A2;
	std::list<int>		A3;

	for (int i = 0; i < 5; i++)
	{
		A2.push_back(A1[i]);
	}
	for (int i = 0; i < 5; i++)
	{
		A3.push_back(A1[i]);
	}
	if (easyfind(A2, 2) == 1)
		std::cout<<"integer 2 found in array"<<std::endl;\
	if (easyfind(A3, -3) == 1)
		std::cout<<"integer -3 found in array"<<std::endl;
	try
	{
		easyfind(A2, 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}