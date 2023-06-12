/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MateriaSource.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/04 17:59:34 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/07 13:22:10 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout<<"MateriaSource default constructor called."<<std::endl;
	for (int i = 0; i < 4; i++) 
		this->_Materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource &another)
{
	std::cout<<"MateriaSource copy constructor called."<<std::endl;
	*this = another;
}

MateriaSource::~MateriaSource()
{
	std::cout<<"MateriaSource destructor called."<<std::endl;
	int i = 0;
	while (this->_Materia[i]!= NULL && i < 4)
	{
		delete this->_Materia[i];
		i++;
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource &another)
{
	for (int i = 0; i < 4; i++)
		this->_Materia[i] = another._Materia[i];
	return (*this);
}

void MateriaSource::learnMateria(AMateria* Materia)
{
	int	i = 0;

	while (this->_Materia[i] != NULL && i < 4)
		i++;
	if (i >= 4)
		std::cout<<"Inventory full. Cannot learn more Materia"<<std::endl;
	else
		this->_Materia[i] = Materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while ((this->_Materia)[i] && ((this->_Materia)[i])->getType() != type && i < 4)
		i++;
	if (i >= 4 || !(this->_Materia)[i])
	{
		std::cout << type << " is not available in inventory"<<std::endl;
		return (NULL);
	}
	std::cout << "Materia " << type << " created\n";
	return (((this->_Materia)[i])->clone());
}