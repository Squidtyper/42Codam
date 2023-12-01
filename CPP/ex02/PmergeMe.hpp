/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/22 14:35:22 by lizhang       #+#    #+#                 */
/*   Updated: 2023/11/10 22:12:53 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <deque>
#include <list>
#include <ctime>

//function to devide into pairs, 
//sort pairs
//start to push to sorted list, use binary search to find where it should be inserted

class dequeSort
{
	private:
		std::deque<int>					_inputs;
		unsigned int					_len;
		std::deque<int *>				_sublist;
		std::deque<int>					_sorted;
		void							_divide();
		void							_sortPair();
		void							_quickSort(int start, int p);
		std::deque<int>::iterator		_binarySearch(int num, unsigned int low, unsigned int high);
		void							_insertMerge();
	
	public:
		dequeSort();
		dequeSort(int *nums, unsigned int len);
		dequeSort(dequeSort const &another);
		~dequeSort();
		dequeSort					&operator=(dequeSort const &another);
		void						sortNumbers();
		void						printResults();
};

class listSort
{
	private:
		std::list<int>				_inputs;
		unsigned int				_len;
		std::list<int *>			_sublist;
		std::list<int>				_sorted;
		void						_divide();
		void						_sortPair();
		void						_quickSort(std::list<int *>::iterator start, std::list<int *>::iterator p);
		std::list<int>::iterator	_binarySearch(int num, std::list<int>::iterator low, std::list<int>::iterator high);
		void						_insertMerge();

	public:
		listSort();
		listSort(int *nums, unsigned int len);
		listSort(listSort const &another);
		~listSort();
		listSort 					&operator=(listSort const &another);
		void						sortNumbers();
		void						printResults();
};

#endif