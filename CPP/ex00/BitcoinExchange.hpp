/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/14 12:58:29 by lizhang       #+#    #+#                 */
/*   Updated: 2023/08/15 15:03:28 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <climits>
#include <cstdlib>

class	Date
{
	private:
		int		_year;
		int		_month;
		int		_day;
		void	error_date(std::string date);
	
	public:
		Date();
		Date(std::string date);
		Date(Date const &another);

		Date	&operator=(Date const &another);
		bool	operator==(Date const &another) const;
		bool	operator<=(Date const &another) const;
		bool	operator<(Date const &another) const;
		bool	operator>=(Date const &another) const;
		bool	operator>(Date const &another) const;

		std::string	stringDate() const;
};

class   ExchangeData
{
	private:
		std::vector<std::pair<std::string, std::string> >	_data;

	public:
		ExchangeData();
		ExchangeData(ExchangeData const &another);
		ExchangeData(std::vector<std::string> const file_content);
		~ExchangeData();

		ExchangeData	&operator=(ExchangeData const &another);

		bool			isEmpty() const;
		std::vector<std::pair<std::string, std::string> >	getExchangeData() const;
};

class	ExchangeRate
{
	private:
		std::map<Date, float> _rates;
		
	
	public:
		ExchangeRate();
		ExchangeRate(ExchangeRate const &another);
		ExchangeRate(std::vector<std::string> const file_content);
		~ExchangeRate();

		ExchangeRate	&operator=(const ExchangeRate &another);

		float	getRateAtDate(Date date) const;
};

void            error_file();
std::vector<std::string>	     read_file(std::string path);
void			exchange(ExchangeData &ED1, ExchangeRate &ER1);

#endif