/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lizhang <lizhang@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/17 15:26:21 by lizhang       #+#    #+#                 */
/*   Updated: 2023/05/21 17:37:30 by lizhang       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <functional>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_totalAmount = _totalAmount + _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	std::cout << "index:" << _accountIndex <<";"<< "amount" << _amount \
	<< ";" << "created" <<std::endl;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"<< _amount << ";" << "closed"<<std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::checkAmount(void) const
{
	return(_amount);
}

int	Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void    Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"\
		<<"amount:"<<_amount<<";"\
		<<"deposit:"<<deposit<<";"<<std::flush;
	_nbDeposits++;
	_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout<<"amount:"<<_amount<<";"\
		<<"nb_deposits:"<<_nbDeposits<<";"<<std::endl;
}

bool    Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"\
	<<"amount:"<<_amount<<";"<<std::flush;
	if (withdrawal<=checkAmount())
	{
		_nbWithdrawals++;
		_amount -= withdrawal;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		std::cout<<"withdrawal:"<<withdrawal<<";"\
		<<"amount:"<<_amount<<";"\
		<<"nb_withdrawals:"<<_nbWithdrawals<<";"<<std::endl;
		return (true);
	}
	std::cout<<"withdrawal:refused"<<std::endl;
	return (false);
}

void Account::displayStatus (void) const
{
	_displayTimestamp();
	std::cout<<"index:"<<_accountIndex<<";"\
	<<"amount:"<<_amount<<";"\
	<<"deposits:"<<_nbDeposits<<";"\
	<<"withdrawals:"<<_nbWithdrawals<<";"\
	<<std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts()<<";"\
	<<"total:"<<getTotalAmount()<<";"\
	<<"deposits:"<<getNbDeposits()<<";"\
	<<"withdrawals:"<<getNbWithdrawals()<<";"\
	<<std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &tstruct);
	std::cout << buf << std::flush;

}
