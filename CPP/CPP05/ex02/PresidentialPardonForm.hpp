/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 15:13:23 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:21:29 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 18:45:04 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/12 19:10:31 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(bool allreadySigned, std::string target);
		PresidentialPardonForm(PresidentialPardonForm &another);
		~PresidentialPardonForm();

		PresidentialPardonForm  &operator=(PresidentialPardonForm &another);
		std::string				getName() const;
		bool					getState() const;
		int						getSignGrade() const;
		int						getExeGrade() const;
		void					beSigned(Bureaucrat &Bureaucrat);
		void					execute(Bureaucrat const &executor) const;
};

#endif