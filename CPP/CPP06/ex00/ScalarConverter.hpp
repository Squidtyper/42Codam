/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/21 18:09:39 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:32:38 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <cmath>

class ScalarConverter
{
	private:
		static char		toChar(std::string input);
		static int		toInt(std::string input);
		static float	toFloat(std::string input);
		static double	toDouble(std::string input);

	public:
		ScalarConverter();
		~ScalarConverter();
		
		static void		convert(std::string input);
};

#endif