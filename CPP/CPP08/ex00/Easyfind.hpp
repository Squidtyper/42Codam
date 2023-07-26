/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 17:27:07 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/12 16:24:16 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <stdexcept>
#include <algorithm>

template <typename T>
int easyfind(T &container, int value)
{
	if (std::find(container.begin(), container.end(), value)!= container.end())
		return (1);
	throw std::invalid_argument("Content not found.");
	return (-1);
}

#endif