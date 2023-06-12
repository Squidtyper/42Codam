/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   A_Animal.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 22:13:24 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/04 15:58:13 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>

class A_Animal
{
	protected:
		std::string _type;

	public:
		A_Animal();
		A_Animal(std::string name);
		A_Animal(const A_Animal &another);
		virtual ~A_Animal();

		A_Animal		&operator=(A_Animal const &another);
		std::string		getType() const;
		virtual void 	makeSound() const = 0;
};

#endif