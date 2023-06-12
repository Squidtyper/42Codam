/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 20:24:00 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:08:05 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
	Cat();
	Cat(std::string type);
	Cat(Cat const &another);
	~Cat();
	
	Cat &operator=(Cat const &another);
	void    makeSound() const;
};

#endif