/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/14 13:00:43 by lizhang       #+#    #+#                 */
/*   Updated: 2023/08/15 15:14:23 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*------------------Date--------------------*/
Date::Date()
{
	std::cout<<"Default Date constructor called. Datde is empty."<<std::endl;
}
		
Date::Date(std::string date)
{
	int pos1;
	int pos2;

	pos1 = date.find("-", 0);
	this->_year = atoi(date.substr(0, pos1).c_str());
	if (this->_year < 1900 || this->_year > 2023)
		this->error_date(date);
	pos2 = date.find("-",pos1 + 1);
	this->_month = atoi(date.substr(pos1 + 1, pos2).c_str());
	if (this->_month < 1 || this->_month > 12)
		this->error_date(date);
	this->_day = atoi(date.substr(pos2 + 1, date.length()).c_str());
	if (this->_month == 2 && this->_day > 29)
		this->error_date(date);
	if (this->_day < 0 || this->_day > 31)
		this->error_date(date);
}

Date::Date(Date const &another)
{
	this->_year = another._year;
	this->_month = another._month;
	this->_day = another._day;
}

Date	&Date::operator=(Date const &another)
{
	this->_year = another._year;
	this->_month = another._month;
	this->_day = another._day;
	return (*this);
}

bool	Date::operator==(Date const &another) const
{
	if (this->_year == another._year && this->_month == another._month && this->_day == another._day)
		return (true);
	return (false);
}
		
bool	Date::operator<=(Date const &another) const
{
	if (this->_year < another._year || (this->_year == another._year &&this->_month< another._month)||\
	(this->_year == another._year && this->_month == another._month &&this->_day <= another._day))
		return (true);
	return (false);
}

bool	Date::operator<(Date const &another) const
{
	if (this->_year < another._year || (this->_year == another._year &&this->_month< another._month)||\
	(this->_year == another._year && this->_month == another._month &&this->_day < another._day))
		return (true);
	return(false);
}

bool	Date::operator>=(Date const &another) const
{
	if (this->_year > another._year || (this->_year == another._year &&this->_month > another._month)||\
	(this->_year == another._year && this->_month == another._month &&this->_day >= another._day))
		return (true);
	return (false);
}

bool	Date::operator>(Date const &another) const
{
	if (this->_year > another._year || (this->_year == another._year && this->_month > another._month)||\
	(this->_year == another._year && this->_month == another._month && this->_day > another._day))
		return (true);
	return (false);
}

std::string	Date::stringDate() const
{
	return(std::to_string(this->_year) + "-"+std::to_string(this->_month)+"-"+std::to_string(this->_day));
}

void	Date::error_date(std::string date)
{
	throw(std::invalid_argument("Error: bad input => " + date));
}

/*------------------ExchangeData--------------------*/

ExchangeData::ExchangeData()
{
	std::cout<<"ExchangeData default constructor called. ExchangeData is empty."<<std::endl;
}

ExchangeData::ExchangeData(ExchangeData const &another)
{
	std::cout<<"ExchangeData copy constructor called"<<std::endl;
	this->_data = another._data;
}

ExchangeData::ExchangeData(std::vector<std::string> const file_content)
{
	std::cout<<"ExchangeData constructor called"<<std::endl;
	for(unsigned int i = 1; i < file_content.size(); i++)
	{
		std::string	date;
		std::string	bitcoin;
		size_t		divide;
		divide = file_content[i].find(" | ", 0);
		date = file_content[i].substr(0, divide);
		if (divide > file_content[i].length())
			bitcoin = "";
		else
			bitcoin = file_content[i].substr(divide + 3, file_content[i].length());
		this->_data.push_back(std::pair<std::string, std::string>(date, bitcoin));
	}
}

ExchangeData::~ExchangeData()
{
	std::cout<<"ExchangeData destructor called."<<std::endl;
}

ExchangeData	&ExchangeData::operator=(ExchangeData const &another)
{
	this->_data = another._data;
	return (*this);
}

bool	ExchangeData::isEmpty() const
{
	if (this->_data.size() == 0)
		return (true);
	return (false);
}

std::vector<std::pair<std::string, std::string> > ExchangeData::getExchangeData() const
{
	return (this->_data);
}


/*------------------ExchangeRate--------------------*/

ExchangeRate::ExchangeRate()
{
	std::cout<<"ExchangeRate default constructor called. ExchangeRate is empty"<<std::endl;
}

ExchangeRate::ExchangeRate(std::vector<std::string> const file_content)
{
	std::cout<<"ExchangeRate constructor called"<<std::endl;
	for(unsigned int i = 1; i < file_content.size(); i++)
	{
		float		rate;
		size_t		divide;
		divide = file_content[i].find(",", 0);
		Date D1(file_content[i].substr(0, divide));
		rate = atof(file_content[i].substr(divide + 1, file_content[i].length()).c_str());
		this->_rates.insert(this->_rates.end(), std::pair<Date, float>(D1, rate));
	}
}

ExchangeRate::ExchangeRate(ExchangeRate const &another)
{
	std::cout<<"ExchangeRate copy constructor called."<<std::endl;
	this->_rates = another._rates;
}

ExchangeRate	&ExchangeRate::operator=(ExchangeRate const &another)
{
	this->_rates = another._rates;
	return (*this);
}

ExchangeRate::~ExchangeRate()
{
	std::cout<<"ExchangeRate destructor called."<<std::endl;
}

float ExchangeRate::getRateAtDate(Date D1) const
{
	std::map<Date, float> rate = this->_rates;
	std::map<Date, float>::iterator it = rate.begin();
	while (it != rate.end())
	{
		if (D1 <=it->first)
		{
			break ;
		}
		it++;
	}
	if (it != rate.begin())
		it--;
	return (it->second);
}

void    error_file()
{
	throw(std::invalid_argument("Error: could not open file."));
}

std::vector<std::string> read_file(std::string path)
{
	std::fstream    file;

	file.open(path);
	if (!file.is_open())
		error_file();
	std::vector<std::string> content;
	std::string buf;
	while(std::getline(file, buf))
	{
		content.push_back(buf);
	}
	return (content);
}

void	exchange(ExchangeData &ED1, ExchangeRate &ER1)
{
	std::vector<std::pair<std::string, std::string> > data;
	data = ED1.getExchangeData();

	for (unsigned int i = 0; i < data.size(); i++)
	{
		if (data[i].second.length() == 0)
			std::cerr<<"Error: bad input"<<std::endl;
		else if (data[i].second.find("-", 0) < data[i].second.length())
			std::cerr<<"Error: not a positive number."<<std::endl;
		else if (atol(data[i].second.c_str()) > INT_MAX)
			std::cerr<<"Error: too large a number."<<std::endl;
		else
		{
			float bitcoin = atof(data[i].second.c_str());
			try
			{
				Date D(data[i].first);
				float rate = ER1.getRateAtDate(D);
				float btc_exchanged = bitcoin * rate;
				std::cout<<data[i].first <<" => "<<btc_exchanged<<std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}