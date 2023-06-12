/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cure.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 19:05:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:38:23 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("Cure")
{
    std::cout<<"Cure default constructor called."<<std::endl;
}

Cure::Cure(Cure &another): AMateria(another)
{
    std::cout<<"Cure copy constructor called."<<std::endl;
    *this = another;
}

Cure::~Cure()
{
    std::cout<<"Cure destructor called."<<std::endl;
}

Cure	&Cure::operator=(Cure &another)
{
    this->_type = another._type;
    return(*this);
}

Cure	*Cure::clone() const
{
    Cure *nCure = new Cure();
    return(nCure);
}

void Cure::use(ICharacter& target)
{
    std::cout<<"* heals "<<target.getName()<<"'s wounds"<<std::endl;
}