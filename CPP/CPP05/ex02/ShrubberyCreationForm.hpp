/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 18:45:04 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/19 17:26:04 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(bool allreadySigned, std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &another);
		~ShrubberyCreationForm();

		ShrubberyCreationForm   &operator=(ShrubberyCreationForm &another);
		std::string				getName() const;
		bool					getState() const;
		int						getSignGrade() const;
		int						getExeGrade() const;
		void					beSigned(Bureaucrat &Bureaucrat);
		void					execute(Bureaucrat const &executor) const;
};

#endif