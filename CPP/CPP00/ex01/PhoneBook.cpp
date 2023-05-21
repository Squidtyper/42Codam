/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 19:17:39 by lizhang       #+#    #+#                 */
/*   Updated: 2023/02/04 19:21:44 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook()
{
}
PhoneBook::~PhoneBook()
{
}

void	PhoneBook::init(void)
{
	for (int i = 0; i < 8; i++)
		this->_Contact[i].init(0);
	this->_newest = 0;
}

void	PhoneBook::add(void)
{
	Contact buf;
	this->_Contact[this->_newest % 8].init(1);
	this->_newest++;
}

void	PhoneBook::_display(void)
{
	std::cout<<std::setw(10)<<"index"<<std::flush;
	std::cout<<"|";
	std::cout<<std::setw(10)<<"first name"<<std::flush;
	std::cout<<"|";
	std::cout<<std::setw(10)<<"last name"<<std::flush;
	std::cout<<"|";
	std::cout<<std::setw(10)<<"nick name"<<std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_Contact[i].check() > 0)
		{
			std::cout<<std::setw(10)<<i<<std::flush;
			this->_Contact[i].print();
		}
	}
}

void	PhoneBook::search(void)
{
	int	index;

	this->_display();
	std::cout<<"enter a digit to show contact information"<<std::endl;
	std::cin>>index;
	while (std::cin.fail())
	{
		std::cout<<"Please search use a digit to SEARCH"<<std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		fflush(stdin);
		std::cin>>index;
	}
	if(index < 0 || index > 7 || this->_Contact[index].check() < 0)
		std::cout<<"Contact not found"<<std::endl;
	else if (this->_Contact[index].check() > 0)
		this->_Contact[index].display_Contact();
}