/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 17:53:28 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/25 14:01:25 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <stack>
# include <list>
# include <deque>
# include <vector>
# include <iterator>
# include <deque>

//the stack should take template inputs
template <typename T>
class MutantStack
{
	private:
		std::deque<T>	_store;

	public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	MutantStack();
	MutantStack(T content);
	MutantStack(std::vector<T> content);
	MutantStack(std::stack<T> content);
	MutantStack(std::deque<T> content);
	~MutantStack();
	MutantStack(MutantStack const &another);

	MutantStack		&operator=(const MutantStack &another);
	operator		std::stack<T>();//this is called a conversion operator, it converts the class to the specified type
	bool			operator==(MutantStack const &another);
	bool			operator<(MutantStack const &another);
	bool			operator<=(MutantStack const &another);
	bool			operator>(MutantStack const &another);
	bool			operator>=(MutantStack const &another);

	bool			empty() const;
	unsigned int	size() const;
	T				top() const;
	void			push(T content);
	void			pop();
	void			emplace(T content);


	iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;
};

template <typename T>
void	swap(MutantStack<T> &A, MutantStack<T> &B);

#endif