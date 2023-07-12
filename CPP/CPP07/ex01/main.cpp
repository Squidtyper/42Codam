/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 16:41:03 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 15:01:29 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main(void)
{
	unsigned int len = 5;
	std::string array[] = {"first", "@", "Another", "5", "6"};
	iter(array, len, uppercase<std::string>);
	for (unsigned int i = 0; i < len; i++ )
	{
		std::cout<<array[i]<<std::endl;
	}
	return (0);
}