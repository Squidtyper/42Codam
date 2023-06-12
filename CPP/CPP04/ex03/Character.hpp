/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 14:58:56 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:15:51 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public ICharacter
{
	private:
		AMateria	*_Materia[4];
		int			_index;
		std::string _name;
    
	public:
		Character();
		Character(std::string name);
		Character(ICharacter &another);
		~Character();

		Character			&operator=(Character const &another);
    
		std::string const 	& getName() const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);
};

#endif