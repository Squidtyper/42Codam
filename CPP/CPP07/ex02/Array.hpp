/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 13:15:44 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 16:05:05 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP


template <typename T>
class Array
{
	private:
		T				*_data;
		unsigned int	_s;

	public:
		Array();
		Array(unsigned int n);
		Array(Array<T> &another);
		~Array();
		Array &operator=(Array<T> &another);
		T &operator[](int index);
		unsigned int	size() const;
};

#endif