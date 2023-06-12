/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AMateria.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:41:09 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/05 19:15:18 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout<<"AMateria default constructor called"<<std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->_type = type;
	std::cout<<"AMateria constructor called."<<std::endl;
}

AMateria::AMateria(AMateria &another)
{
	*this = another;
	std::cout<<"AMateria copy constructor called."<<std::endl;
}

AMateria::~AMateria()
{
	std::cout<<"AMateria destructor called."<<std::endl;
}

std::string const & AMateria::getType() const //Returns the materia type
{
	return(this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout<<"Unspecified materia used on" <<target.getName()<<std::endl;
}