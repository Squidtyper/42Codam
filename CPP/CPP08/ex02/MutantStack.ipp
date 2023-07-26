/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.ipp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 17:53:25 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/26 16:17:50 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout<<"MutantStack default constructor called."<<std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(T content)
{
	std::cout<<"MutantStack constructor called."<<std::endl;
	std::deque<T>	newStack(content);
	this->_store = newStack;
}

template <typename T>
MutantStack<T>::MutantStack(std::stack<T> content)
{
	std::cout<<"MutantStack stack constructor called."<<std::endl;
	std::deque<T> newStack;
	while (!content.empty())
	{
		newStack.push_front(content.top());
		content.pop();
	}
	this->_store = newStack;
}

template <typename T>
MutantStack<T>::MutantStack(std::vector<T> content)
{
	std::cout<<"MutantStack vector constructor called."<<std::endl;
	std::deque<T> newStack;
	while (!content.empty())
	{
		newStack.push_back(content.front());
		content.erase(content.begin());
	}
	this->_store = newStack;
}

template <typename T>
MutantStack<T>::MutantStack(std::deque<T> content)
{
	std::cout<<"MutantStack deque constructor called."<<std::endl;
	this->_store = content;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &another)
{
	std::cout<<"MutantStack copy constructor called."<<std::endl;
	this->_store = another._store;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout<<"MutantStack destructor called."<<std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &another)
{
	this->_store = another._store;
	return(*this);
};

template <typename T>
MutantStack<T>::operator std::stack<T>()
{
	std::stack<T> newStack(this->_store);
	return (newStack);
}

template <typename T>
bool MutantStack<T>::operator==(MutantStack<T> const &another)
{
	return (this->_store == another._store);
}

template <typename T>
bool MutantStack<T>::operator<(MutantStack<T> const &another)
{
	return (this->_store < another._store);
}

template <typename T>
bool MutantStack<T>::operator<=(MutantStack<T> const &another)
{
	return (this->_store <= another._store);
}

template <typename T>
bool MutantStack<T>::operator>(MutantStack const &another)
{
	return (this->_store > another._store);
}

template <typename T>
bool MutantStack<T>::operator>=(MutantStack<T> const &another)
{
	return (this->_store >= another._store);
}

template <typename T>
bool MutantStack<T>::empty() const
{
	if (this->_store.empty() == true)
		return (true);
	return (false);
}

template <typename T>
unsigned int MutantStack<T>::size() const
{
	return(this->_store.size());
}

template <typename T>
T MutantStack<T>::top() const
{
	return (this->_store.back());
}

template <typename T>
void MutantStack<T>::push(T content)
{
	this->_store.push_back(content);
}

template <typename T>
void MutantStack<T>::pop()
{
	this->_store.pop_back();
}

template <typename T>
void MutantStack<T>::emplace(T content)
{
	this->_store.emplace_back(content);
}


template <typename T>
void	swap(MutantStack<T> &A, MutantStack<T> &B)
{
	std::deque<T> 	AData;
	std::deque<T> 	BData;
	for (unsigned int i = 0; i < A.size(); i++)
	{
		AData.push_back(A[i]);
	}
	for (unsigned int i = 0; i < B.size(); i++)
	{
		BData.push_back(B[i]);
	}
	while(!A.empty())
		A.pop_back();
	while (!B.empty())
		B.pop_back();
	for (unsigned int i = 0; i < AData.size(); i++)
	{
		A.push_back(AData[i]);
	}
	for (unsigned int i = 0; i < BData.size(); i++)
	{
		B.push_back(BData[i]);
	}
}

template <typename T> 
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->_store.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->_store.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->_store.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const 
{
	return (this->_store.end());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->_store.rbegin());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const 
{
	return (this->_store.rbegin());
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->_store.rend());
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->_store.rend());
} 