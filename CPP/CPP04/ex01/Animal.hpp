/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 22:13:24 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 22:51:40 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal();
		Animal(std::string name);
		Animal(const Animal &another);
		virtual ~Animal();

		Animal			&operator=(Animal const &another);
		void			setType(std::string type);
		std::string		getType() const;
		virtual void 	makeSound() const;
};

#endif