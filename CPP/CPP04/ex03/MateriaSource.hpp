/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:36:34 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 12:35:30 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_Materia[4];

	public:
		MateriaSource();
		MateriaSource(MateriaSource &another);
		virtual ~MateriaSource();
		
		MateriaSource		&operator=(MateriaSource &another);
		virtual void		learnMateria(AMateria* Materia);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif