/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/14 17:54:23 by lizhang       #+#    #+#                 */
/*   Updated: 2023/02/04 19:19:22 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>

Contact::Contact()
{
}

Contact::~Contact()
{
}

static std::string getinput(void)
{
    std::string line;
    getline(std::cin, line, '\n');
    while (line.length() == 0)
    {
        std::cout<<"field cannot be empty: "<<std::flush;
        getline(std::cin, line, '\n');
    }
    return(line);
}

void Contact::init(int exist)
{
    if (exist == 0)
        this->_exist = false;
    else
    {
        std::cout<<"First name: "<<std::flush;
        this->_firstname = getinput();
        std::cout<<"Last name: "<<std::flush;
        this->_lastname = getinput();
        std::cout<<"Nick name: "<<std::flush;
        this->_nickname = getinput();
        std::cout<<"Phone number: "<<std::flush;
        this->_phonenumber = getinput();
        std::cout<<"Darkest secret: "<<std::flush;
        this->_darkestsecret = getinput();
        this->_exist = true;
        std::cout<<"Contact created successfully"<<std::endl;
    }
}

int Contact::check(void)
{
    if (this->_exist == false)
        return (-1);
    return (1);
}

static void print_str_format(std::string str)
{
	int		len;

	len = str.length(); 
	if (len > 10)
	{
		std::cout<<str.substr(0, 9);
		std::cout<<"."<<std::flush;
	}
	else if (len == 10)
		std::cout<<str<<std::flush;
	else
		std::cout<<std::setw(10)<<str<<std::flush;
}

void Contact::print(void)
{
	std::cout<<"|";
	print_str_format(this->_firstname);
	std::cout<<"|";
	print_str_format(this->_lastname);
	std::cout<<"|";
	print_str_format(this->_nickname);
	std::cout<<std::endl;
}

void Contact::display_Contact(void)
{
	std::cout<<"first name: "<<this->_firstname<<std::endl;
	std::cout<<"last name: "<<this->_lastname<<std::endl;
	std::cout<<"nick name: "<<this->_nickname<<std::endl;
	std::cout<<"phone number: "<<this->_phonenumber<<std::endl;
}
