/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/11 16:38:55 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 15:05:26 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename W, typename F>
void iter(T data, W len, F f)
{
	if (len < 0)
		throw (std::invalid_argument("len should be a positive number"));
	for(size_t i = 0; i < (size_t)len; i++)
	{
		f(data[i]);
	}
}

template <typename T>
void    uppercase(T &array)
{
	std::transform(array.begin(), array.end(), array.begin(),::toupper);
}

#endif