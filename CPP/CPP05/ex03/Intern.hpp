/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/19 17:04:38 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:06:40 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
	AForm	*makeSCF(std::string target);
	AForm	*makeRRF(std::string target);
	AForm	*makePPF(std::string target);

	public:
		Intern();
		Intern(Intern &another);
		~Intern();

		AForm	*makeForm(std::string type, std::string target);
		typedef	AForm  *(Intern::*MF)(std::string target);
};

#endif