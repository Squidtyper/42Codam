/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 22:21:54 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 22:47:19 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_Brain;

	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const &another);
		~Dog();
	
	Dog		&operator=(Dog const &another);
	void    makeSound() const;
	void	setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
};

#endif