/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Data.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 15:37:47 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/08 17:45:34 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>
#include <string>

class Data
{
	private:
		std::string _str1;
		std::string _str2;
		int			_number;

	public:
		Data(std::string str1, std::string str2, int number);
		Data(Data &another);
		~Data();

		Data 		&operator=(Data &another);
		std::string	const getStr1() const;
		std::string	const getStr2() const;
		int			getNumber() const;
};

#endif