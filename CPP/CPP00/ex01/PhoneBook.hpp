/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 18:08:58 by lizhang       #+#    #+#                 */
/*   Updated: 2023/02/04 18:55:22 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact			_Contact[8];
		unsigned int	_newest;
		void	_display(void);

	public:
		PhoneBook();
		~PhoneBook();
		void    init(void);
		void    add(void);
		void    search(void);
};

#endif