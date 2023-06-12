/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 15:33:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/06/12 16:25:40 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Serializer
{
	public:
		Serializer();
		Serializer(Serializer &another);
		~Serializer();

		static Data			*deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data *ptr);
};

#endif