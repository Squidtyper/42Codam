/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 18:05:58 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 18:16:32 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(WrongCat const &another);
		~WrongCat();
		
		WrongCat		&operator=(WrongCat const &another);
		void    		makeSound() const;
};

#endif