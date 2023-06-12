/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 19:01:16 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:01:05 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <string>
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
	Ice();
	Ice(Ice &another);
	~Ice();
	
	Ice		&operator=(Ice &another);

	using AMateria::clone;
	Ice		*clone() const;
	void	use(ICharacter& target);
};

#endif