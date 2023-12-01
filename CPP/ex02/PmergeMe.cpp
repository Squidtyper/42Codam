/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:26 by lizhang       #+#    #+#                 */
/*   Updated: 2023/11/13 13:17:24 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <unistd.h>
#include <cmath>

/*Quicksort principle: 
find pivot point (the last item in list) int val
start with list[i] i = 0
read if list[i] <= val, i++
if list[i] > val, look for the next value list[j] (j = i + 1) 
if list[j] <= val, swap the 2, if j reaches the end, stop
this round ends, take a new pivot point
when i sucessfully reaches the one to last value, the list is sorted
example 1 3 5 2 8 10 5
5 is pivot value, i moves to 8 because 8 > 5, j moves to 10
nothing to swap within the partition
8 and 5 swiches places because j reached one before the pivot
1 3 5 2 5 10 8
now 5 is in the middle of the array, recursively sort both sides separately
sort 1 3 5 2 using 2 a pivot, sort 10 8 using 8 as pivot
*/

// --------------------------------dequeSort----------------------------------//
void    dequeSort::_divide()
{
	//devide the inputs numbers in pairs of 2
	unsigned int i = 0;
	while (i < this->_len)
	{
		int *	pair = new int[2];
		pair[0] = this->_inputs[i];
		i++;
		if (i < this->_len)
		{
			pair[1] = this->_inputs[i];
			i++;
		}
		else
			pair[1] = -1;
		this->_sublist.push_back(pair);
	}
}


void	dequeSort::_sortPair()
{
	for (unsigned int i = 0; i < this->_sublist.size(); i++)
	{
		if (sizeof(this->_sublist[i][1]> 0))
		{
			if (this->_sublist[i][0] < this->_sublist[i][1])
				std::swap(this->_sublist[i][0], this->_sublist[i][1]);
		}
	}
	//after this function, the larger integer is at the beginning
}

void	dequeSort::_quickSort(int start, int p)
{	
	//int i is the lower end of the partition
	//p is the position of the pivot value
	int i = start;
	if (i >= p - 1)
	{
		if (this->_sublist[i][0] > this->_sublist[p][0])
			std::swap(this->_sublist[i], this->_sublist[p]);
		return ;
	}
	int j = i + 1;
	while (j < p && i < p)
	{
		while (i < p && this->_sublist[i][0] <= this->_sublist[p][0])
			i++;
		if (j <= i)
			j = i+1;
		if (this->_sublist[i][0] > this->_sublist[p][0] && this->_sublist[j][0] <= this->_sublist[p][0])
		{
			std::swap(this->_sublist[i], this->_sublist[j]);
			i++;
		}
		j++;
	}
	std::deque<int *>::iterator it =  this->_sublist.begin() + i;
	this->_sublist.insert(it, this->_sublist[p]);
	std::deque<int *>::iterator it2 = this->_sublist.begin() + p + 1;
	this->_sublist.erase(it2);
	if (start < i - 1)
		_quickSort(start, i - 1);
	if(i + 1 < p)
		_quickSort(i + 1, p);
}
		
std::deque<int>::iterator	dequeSort::_binarySearch(int num, unsigned int low, unsigned int high)
{
	if (high - low <= 1)
	{
		if (num >= this->_sorted[low])
			return(this->_sorted.begin() + low + 1);
		else
			return(this->_sorted.begin());
	}
	unsigned int i = (low + high)/2;
	if (this->_sorted[i] > num)
		return(_binarySearch(num, low, i));
	else
		return(_binarySearch(num, i, high));
}

void	dequeSort::_insertMerge()
{
	for(unsigned int i = 0; i < this->_sublist.size(); i++)
	{
		this->_sorted.push_back(this->_sublist[i][0]);
	}
	for (unsigned int i = 0; i < this->_sublist.size(); i++)
	{
		if (this->_sublist[i][1] > 0)
		{
			std::deque<int>::iterator loc = _binarySearch(this->_sublist[i][1], 0, this->_sorted.size() - 1);
			this->_sorted.insert(loc, this->_sublist[i][1]);
		}
	}
}
	
dequeSort::dequeSort()
{
	std::cout<<"dequeSort default constructor called. The class is now empty."<<std::endl;
}

dequeSort::dequeSort(int *nums, unsigned int len)
{
	std::cout<<"dequeSort constructor called. Numbers are being saved."<<std::endl;
	for (unsigned int i = 0; i < len; i++)
		this->_inputs.push_back(nums[i]);
	this->_len = len;
}

dequeSort::dequeSort(dequeSort const &another)
{
	std::cout<<"dequeSort copy constructor called."<<std::endl;
	this->_inputs= another._inputs;
	this->_sublist = another._sublist;
	this->_sorted = another._sorted;
	this->_len = another._len;
}

dequeSort::~dequeSort()
{
	std::cout<<"dequeSort destructor called."<<std::endl;
	for(unsigned int i= 0; i < this->_sublist.size(); i++)
		delete[] this->_sublist[i];
}

dequeSort	&dequeSort::operator=(dequeSort const &another)
{
	this->_inputs= another._inputs;
	this->_sublist = another._sublist;
	this->_sorted = another._sorted;
	this->_len = another._len;
	return (*this);
}

void	dequeSort::sortNumbers()
{
	this->_divide();
	this->_sortPair();
	this->_quickSort(0, this->_sublist.size() - 1);
	this->_insertMerge();
}

void	dequeSort::printResults()
{
	std::cout<<"Before: "<<std::flush;
	for(unsigned int i = 0; i < this->_inputs.size(); i++)
		std::cout<<this->_inputs[i]<<" "<<std::flush;
	std::cout<<std::endl;
	std::cout<<"After:  "<<std::flush;
	if (this->_sorted.empty())
	{
		std::cerr<<"Input not sorted. Use ::sortNumbers() first to sort the inputs"<<std::endl;
		return ;
	}
	else
	{
		for(unsigned int i = 0; i < this->_sorted.size(); i++)
		std::cout<<this->_sorted[i]<<" "<<std::flush;
	}
	std::cout<<std::endl;
}

//-----------------------listSort--------------------------//
void    listSort::_divide()
{
	//devide the inputs numbers in pairs of 2
	std::list<int>::iterator ilist=this->_inputs.begin();
	while (ilist != this->_inputs.end())
	{
		int *	pair = new int[2];
		pair[0] = *ilist;
		ilist++;
		if (ilist != this->_inputs.end())
		{
			pair[1] = *ilist;
			ilist++;
		}
		else
			pair[1] = -1;
		this->_sublist.push_back(pair);
	}
}


void	listSort::_sortPair()
{
	std::list<int *>::iterator it=this->_sublist.begin();
	while (it!= this->_sublist.end())
	{
		if (sizeof(*it) > 0)
		{
			if ((*it)[0] < (*it)[1])
				std::swap((*it)[0], (*it)[1]);
		}
		it++;
	}
}

void	listSort::_quickSort(std::list<int *>::iterator start, std::list<int *>::iterator p)
{
	if (start == p)
		return ;
	//the condition that the distance of start and iterator is 1 or less
	if (std::distance(start, p) <= 1)
	{
		if (start != p)
		{
			if ((*start)[0] > (*p)[0])
				std::swap((*start), (*p));
		}
		return ;
	}
	std::list<int *>::iterator it = start;
	//the condition that the largest is at the p, then it is at the p, it2 is same as it
	//the condition that the smallest is at the p, it is at position 1, then it2 is at the p
	//the condition that all numbers are the same, it and it2 is both at the start, then it gets moved on till p
	std::list<int *>::iterator it2;
	while (it != p && it2 != p)
	{
		while ((*it)[0] < (*p)[0])
			it++;
		std::list<int *>::iterator it2 = it;
		while ((*it2)[0] > (*p)[0])
			it2++;
		if (it == start && it2 == start)
			return ;
		if ((*it)[0] > (*p)[0] && (*it2)[0]<(*it)[0])
			std::swap((*it), (*it2));
		if (it != p)
			it++;
	}
	//in case that p value is smallest, then it should be placed at the start
	//in case that p value is in the middle, then it should be placed before it
	//in case that p value is the largest, then nothing should be done
	if (it2 == p, it != p)
	{
		this->_sublist.insert(start, (*p));
		this->_sublist.erase(std::next(p, 1));
	}
	std::list<int *>::iterator end = it;
	end--;
	_quickSort(start, end);
	if (it == p || ++it == p)
		return ;
	_quickSort(it, p);
}

	
		
std::list<int>::iterator	listSort::_binarySearch(int num, std::list<int>::iterator low, std::list<int>::iterator high)
{
	if (std::distance(low, high) <= 1)
	{
		if (num >= (*low))
			return(++low);
		else
			return(low);
	}
	int dist = std::distance(low, high);
	dist = dist/2;
	std::list<int>::iterator i = std::next(low, dist);
	if ((*i) > num)
		return(_binarySearch(num, low, i));
	else
		return(_binarySearch(num, i, high));
}

void	listSort::_insertMerge()
{
	for(std::list<int *>::iterator i = this->_sublist.begin(); i != this->_sublist.end(); i++)
	{
		this->_sorted.push_back((*i)[0]);
	}
	for (std::list<int *>::iterator i = this->_sublist.begin(); i != this->_sublist.end(); i++)
	{
		if ((*i)[1] > 0)
		{
			std::list<int>::iterator loc = _binarySearch((*i)[1], this->_sorted.begin(), this->_sorted.end()--);
			this->_sorted.insert(loc, (*i)[1]);
		}
	}
}

listSort::listSort()
{
	std::cout<<"listSort default constructor called. The class is now empty."<<std::endl;
}

listSort::listSort(int *nums, unsigned int len)
{
	std::cout<<"listSort constructor called. Numbers are being saved."<<std::endl;
	for (unsigned int i = 0; i <len; i++)
	{
		this->_inputs.push_back(nums[i]);
	}
	this->_len = len;
}

listSort::listSort(listSort const &another)
{
	std::cout<<"listSort copy constructor called."<<std::endl;
	this->_inputs= another._inputs;
	this->_sublist = another._sublist;
	this->_sorted = another._sorted;
	this->_len = another._len;
}
		
listSort::~listSort()
{
	std::cout<<"listSort destructor called."<<std::endl;
	for(std::list<int *>::iterator i = this->_sublist.begin(); i != this->_sublist.end()--; i++)
		delete[] *(i);
}

listSort 	&listSort::operator=(listSort const &another)
{
	this->_inputs= another._inputs;
	this->_sublist = another._sublist;
	this->_sorted = another._sorted;
	this->_len = another._len;
	return (*this);
}

void	listSort::sortNumbers()
{
	this->_divide();
	this->_sortPair();
	this->_quickSort(this->_sublist.begin(), --this->_sublist.end());
	std::cout<<"after quickSort"<<std::endl;
	for (std::list<int *>::iterator it = this->_sublist.begin(); it != this->_sublist.end(); it++)
	{
		std::cout<<(*it)[0]<<" ";
	}
	std::cout<<std::endl;
	this->_insertMerge();
}


void	listSort::printResults()
{
	std::cout<<"Before: "<<std::flush;
	for(std::list<int>::iterator it = this->_inputs.begin(); it != this->_inputs.end(); it++)
		std::cout<<*it<<" "<<std::flush;
	std::cout<<std::endl;
	std::cout<<"After:  "<<std::flush;
	if (this->_sorted.empty())
	{
		std::cerr<<"Input not sorted. Use ::sortNumbers() first to sort the inputs"<<std::endl;
		return ;
	}
	else
	{
		for(std::list<int>::iterator it = this->_sorted.begin(); it != this->_sorted.end(); it++)
			std::cout<<*it<<" "<<std::flush;
	}
	std::cout<<std::endl;
}