/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Character.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 18:49:50 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:38:02 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout<<"ICharacter default constructor called."<<std::endl;
	this->_index = 0;
	for (int i = 0; i < 4; i++) 
		this->_Materia[i] = NULL;
}

Character::Character(std::string name)
{
	std::cout<<"ICharacter constructor called."<<std::endl;
	this->_name = name;
	this->_index = 0;
	for (int i = 0; i < 4; i++) 
		this->_Materia[i] = NULL;
}

Character::Character(ICharacter &another)
{
	std::cout<<"ICharacter copy constructor called."<<std::endl;
	*this = another;
}

Character::~Character()
{
	std::cout<<"ICharacter destructor called."<<std::endl;
}

Character	&Character::operator=(Character const &another)
{
	for(int i= 0; i < 4; i++)
		this->_Materia[i] = another._Materia[i];
	this->_name = another._name;
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (this->_index < 4)
	{
		this->_Materia[this->_index] = m;
		this->_index++;
	}
	else
		std::cout<<"Materia inventory is full. Cannot equip."<<std::endl;
}

void	Character::unequip(int idx)
{
	if (this->_Materia[idx] == NULL)
		std::cout<<"No Materia is equiped at this index. Cannot unequip"<<std::endl;
	else
	{
		this->_Materia[idx] = NULL;
		this->_index--;
	}
}

void 	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4 || this->_Materia[idx] == NULL)
		std::cout<<"No Materia at this index."<<std::endl;
	else
	{
		std::cout<<this->getName()<<std::flush;
		this->_Materia[idx]->use(target);
	}
}