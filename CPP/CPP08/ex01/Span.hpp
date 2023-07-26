/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 16:30:20 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/26 16:13:13 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iterator>

class Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_store;
	
	public:
		typedef std::vector<int>::iterator iterator;
		Span();
		Span(unsigned int n);
		Span(Span const &another);
		~Span();

		Span			&operator=(Span const &another);
		int				&operator[](int index);
		
		long			shortestSpan() const;
		long			longestSpan() const;
		void			randFill(int range_start, int range_end);
		iterator 		begin();
		iterator 		end();
		void			addNumber(int number);
};

#endif