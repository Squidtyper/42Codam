/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:24:00 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 22:53:15 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_Brain;

	public:
	Cat();
	Cat(std::string type);
	Cat(Cat const &another);
	~Cat();
	
	Cat     &operator=(Cat const &another);
	void    makeSound() const;
	void	setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
};

#endif