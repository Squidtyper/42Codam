/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:14 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:17:51 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const		_name;
		std::string const		_target;
		bool					_signed;
		int const				_signGrade;
		int const				_exeGrade;
		std::invalid_argument	GradeTooHighExeption();
		std::invalid_argument	GradeTooLowException();
	
	public:
		AForm();
		AForm(std::string name, bool allreadySigned, int signGrade, int exeGrade, std::string target);
		AForm(AForm &another);
		virtual	~AForm() = 0;

		AForm					&operator=(AForm &another);
		std::string				getName() const;
		std::string				getTarget() const;
		bool					getState() const;
		int						getSignGrade() const;
		int						getExeGrade() const;
		virtual void			beSigned(Bureaucrat &Bureaucrat) = 0;
		virtual void			execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &os, const AForm &a);

#endif