/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/07 13:55:00 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:09:27 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>

class Bureaucrat
{
	private:
		std::string	const	_name;
		int					_grade;
		std::invalid_argument const GradeTooHighException();
		std::invalid_argument const GradeTooLowException();

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat &another);
		~Bureaucrat();

		Bureaucrat	&operator=(Bureaucrat &another);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &B);


#endif