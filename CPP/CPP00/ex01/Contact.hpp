/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/12 13:21:26 by lizhang       #+#    #+#                 */
/*   Updated: 2023/02/04 18:51:42 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>
#include <string>

class Contact
{
	private:
		std::string		_firstname;
		std::string 	_lastname;
		std::string 	_nickname;
		std::string 	_phonenumber;
		std::string 	_darkestsecret;
		bool			_exist;

	public:
		Contact();
		~Contact();
		void			init(int exist);
		int				check(void);
		void			print(void);
		void			display_Contact(void);
};

#endif