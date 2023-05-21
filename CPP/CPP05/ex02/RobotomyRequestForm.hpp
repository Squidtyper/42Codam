/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 19:15:18 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:26:54 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(bool allreadySigned, std::string target);
		RobotomyRequestForm(RobotomyRequestForm &another);
		~RobotomyRequestForm();

		RobotomyRequestForm		&operator=(RobotomyRequestForm &another);
		std::string				getName() const;
		bool					getState() const;
		int						getSignGrade() const;
		int						getExeGrade() const;
		void					beSigned(Bureaucrat &Bureaucrat);
		void					execute(Bureaucrat const &executor) const;
};
#endif