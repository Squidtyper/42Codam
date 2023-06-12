/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/30 22:04:58 by lizhang       #+#    #+#                 */
/*   Updated: 2023/04/30 23:35:45 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain();
		Brain(Brain const &another);
		~Brain();
	
		Brain		&operator=(Brain const &another);
		void		setIdea(int index, std::string const idea);
		std::string	getIdea(int index) const;
};


#endif