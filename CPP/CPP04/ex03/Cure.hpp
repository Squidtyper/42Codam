/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 19:01:16 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:10:33 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <string>
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
	Cure();
	Cure(Cure &another);
	~Cure();
	
	Cure	&operator=(Cure &another);

	using AMateria::clone;
	Cure	*clone() const;
	void	use(ICharacter& target);
};

#endif