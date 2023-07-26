/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 16:30:17 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/26 16:31:22 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <ctime>

Span::Span()
{
	std::cout<<"Span default constructor called."<<std::endl;
	this->_N = 0;
}

Span::Span(unsigned int n)
{
	std::cout<<"Span constructor called."<<std::endl;
	this->_N = n;
}

Span::Span(Span const &another)
{
	std::cout<<"Span copy constructor called."<<std::endl;
		this->_store = another._store;
	this->_N = another._N;
}

Span::~Span()
{
	std::cout<<"Span destructor called."<<std::endl;
}

Span &Span::operator=(Span const &another)
{
	this->_store = another._store;
	this->_N = another._N;
	return (*this);
}

long	Span::shortestSpan() const
{
	long span;
	long min_span = UINT32_MAX;

	if (this->_store.size() <= 1)
		throw(std::length_error("The container doesn't contain enough elements to get span."));
	for(unsigned int i = 0; i < (this->_store.size() - 1); i++)
	{
		for (unsigned int j = i + 1; j < this->_store.size(); j++)
		{
			span = abs(this->_store[i] - this->_store[j]);
			if (span < min_span)
				min_span = span;
		}
	}
	return (min_span);
}

long	Span::longestSpan() const
{
	long span;
	long max_span = 0;

	if (this->_store.size() <= 1)
		throw(std::length_error("The container doesn't contain enough elements to get span."));
	for(unsigned int i = 0; i < (this->_store.size() - 1); i++)
	{
		for (unsigned int j = i + 1; j < this->_store.size(); j++)
		{
			span = abs(this->_store[i] - this->_store[j]);
			if (span > max_span)
				max_span = span;
		}
	}
	return (max_span);
}

void	Span::addNumber(int number)
{
	if (this->_store.size() < (this->_N))
		this->_store.push_back(number);
	else
		throw(std::out_of_range("Out of storage range."));
}

Span::iterator Span::begin()
{
	return(this->_store.begin());
}

Span::iterator Span::end()
{
	return (this->_store.end());
}

void	Span::randFill(int range_start, int range_end)
{
	srand(std::time(nullptr));
	for (unsigned int i = 0; i < this->_N; i++)
		this->_store.push_back(range_start + (rand() % (range_end - range_start + 1)));
}

int	&Span::operator[](int index)
{
	return(this->_store[index]);
}