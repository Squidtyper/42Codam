/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:24:00 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:38:12 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "A_Animal.hpp"
#include "Brain.hpp"

class Cat: public A_Animal
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