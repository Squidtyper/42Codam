/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/18 12:23:10 by lizhang       #+#    #+#                 */
/*   Updated: 2023/07/26 16:27:03 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "MutantStack.ipp"
#include <list>

int main()
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
std::cout<<s.top()<<std::endl;
s.pop();
std::cout<<s.top()<<std::endl;
return 0;
}

// int main()
// {
// std::list<int> mstack;
// mstack.push_back(5);
// mstack.push_back(17);
// std::cout << mstack.back() << std::endl;
// mstack.pop_back();
// std::cout << mstack.size() << std::endl;
// mstack.push_back(3);
// mstack.push_back(5);
// mstack.push_back(737);
// //[...]
// mstack.push_back(0);
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
// ++it;
// --it;
// while (it != ite)
// {
// std::cout << *it << std::endl;
// ++it;
// }
// std::list<int> s(mstack);
// std::cout<<s.back()<<std::endl;
// s.pop_back();
// std::cout<<s.back()<<std::endl;
// return 0;
// }