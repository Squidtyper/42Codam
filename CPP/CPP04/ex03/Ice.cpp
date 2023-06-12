/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Ice.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 19:05:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:11:21 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("Ice")
{
    std::cout<<"Ice default constructor called."<<std::endl;
}

Ice::Ice(Ice &another): AMateria(another)
{
    std::cout<<"Ice copy constructor called."<<std::endl;
    *this = another;
}

Ice::~Ice()
{
    std::cout<<"Ice destructor called."<<std::endl;
}

Ice		&Ice::operator=(Ice &another)
{
    this->_type = another._type;
    return(*this);
}

Ice		*Ice::clone() const
{
    Ice *nIce = new Ice();
    return(nIce);
}

void Ice::use(ICharacter& target)
{
    std::cout<<"* shoots an ice bolt at"<<target.getName()<<std::endl;
}