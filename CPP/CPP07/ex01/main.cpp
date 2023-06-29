/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 16:41:03 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/11 18:11:33 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main(void)
{
	unsigned int len = 5;
	std::string array[] = {"first", "@", "Another", "5", "6"};
	iteration(*array, len, uppercase);
	for (unsigned int i = 0; i < len; i++ )
	{
		std::cout<<array[i]<<std::endl;
	}
}