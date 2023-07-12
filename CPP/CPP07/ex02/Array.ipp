/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.ipp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/01 13:34:40 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/03 16:04:56 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array()
{
	std::cout<<"Array default constructor called."<<std::endl;
	this->_s = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout<<"Array constructor called."<<std::endl;
	this->_data = new T[n];
	this->_s = n;
}

template <typename T>
Array<T>::Array(Array<T> &another)
{
	std::cout<<"Array copy constructor called."<<std::endl;
	this->_data = new T[another.size()];
	this->_s = another.size();
	for (unsigned int i = 0; i < another.size(); i++)
	{
		this->_data[i] = another[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	std::cout<<"Array destructor called."<<std::endl;
	delete[] this->_data;
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &another)
{
	std::cout<<"Array copy constructor called."<<std::endl;
	delete[] this->_data;
	this->_data = new T[another.size()];
	this->_s = another.size();
	for (unsigned int i = 0; i < another.size(); i++)
	{
		this->_data[i] = another[i];
	}
	return(*this);
}


template <typename T>
T	&Array<T>::operator[](int index)
{
	if (index < 0 || (unsigned int)index >= this->size())
	{
		throw(std::invalid_argument("Index out of range."));
	}
	return (this->_data[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return(this->_s);
}
