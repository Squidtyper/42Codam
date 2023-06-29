/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 16:38:55 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/11 18:26:33 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename W>
void iteration(T &data, W len, void (*f)(T))
{
	int i = 0;
	while (i < (int)len)
	{
		std::cout<<data<<std::endl;
		f(&data[i]);
	}
}

template <typename T>
void    uppercase(T str)
{
	std::string cast = static_cast<std::string>(str);
	std::transform(cast.begin(), cast.end(), cast.begin(),::toupper);
	std::cout <<cast<<std::endl;
}

//why will the function only move 1 bit in the while loop and not move up one string???

#endif