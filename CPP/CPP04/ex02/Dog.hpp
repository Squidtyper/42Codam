/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 22:21:54 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:37:59 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "A_Animal.hpp"
#include "Brain.hpp"

class Dog: public A_Animal
{
	private:
		Brain	*_Brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &another);
		~Dog();
	
		Dog			&operator=(Dog const &another);
		void		makeSound() const;
		void		setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};

#endif