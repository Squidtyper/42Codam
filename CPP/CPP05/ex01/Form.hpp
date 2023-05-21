/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 13:17:14 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/12 18:24:50 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const		_name;
		bool					_signed;
		int const				_signGrade;
		int const				_exeGrade;
		std::invalid_argument	GradeTooHighExeption();
		std::invalid_argument	GradeTooLowException();
	
	public:
		Form();
		Form(std::string name, bool allreadySigned, int signGrade, int exeGrade);
		Form(Form &another);
		~Form();

		Form					&operator=(Form &another);
		std::string				getName() const;
		bool					getState() const;
		int						getSignGrade() const;
		int						getExeGrade() const;
		void					beSigned(Bureaucrat &Bureaucrat);
};

std::ostream	&operator<<(std::ostream &os, const Form &a);

#endif