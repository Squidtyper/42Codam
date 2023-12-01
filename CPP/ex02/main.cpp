/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:39:54 by lizhang       #+#    #+#                 */
/*   Updated: 2023/09/01 17:35:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <chrono>
#include <iomanip>
#include <cstring>
#include <climits>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr<<"Error"<<std::endl;
		return (1);
	}
	int *inputs = new int[ac - 1];
	for (int i = 1; i < ac; i++)
	{
		try
		{
			for (size_t j = 0; j < strlen(av[i]); j++)
			{
				if (isdigit(av[i][j]) != 1 && av[i][j] != '+')
					throw(std::invalid_argument("Error"));
			}
		}
		catch (const std::exception &e)
		{
			std::cerr<<e.what()<<std::endl;
			delete[] inputs;
			return (1);
		}
		long int test;
		test = atol(av[i]);
		if (test < 0 || test > (long int)INT_MAX) 
		{
			std::cerr<<"Error"<<": Only positive integers accepted!"<<std::endl;
			delete[] inputs;
			return (1);
		}
		inputs[i - 1] = (int)test;
	}
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	dequeSort dS1(inputs, ac - 1);
	dS1.sortNumbers();
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	dS1.printResults();
	std::chrono::duration<float, std::micro> duration = end - start;
	std::cout<<"time to process a range of "<<std::setw(4)<<ac - 1;
	std::cout<<" elements with std::deque :"<<std::setw(12)<<std::fixed<<std::setprecision(5)<<duration.count()<<" us"<<std::endl;
	start = std::chrono::high_resolution_clock::now();
	listSort lS1(inputs, ac - 1);
	lS1.sortNumbers();
	end = std::chrono::high_resolution_clock::now();
	lS1.printResults();
	duration = end - start;
	std::cout<<"time to process a range of "<<std::setw(4)<<ac - 1;
	std::cout<<" elements with std::list :"<<std::setw(12)<<std::fixed<<std::setprecision(5)<<duration.count()<<" us"<<std::endl;
	delete [] inputs;
	return (0);
}
