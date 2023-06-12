/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 22:21:54 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 21:47:50 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &another);
		~Dog();
	
	Dog		&operator=(Dog const &another);
	void    makeSound() const;
};

#endif