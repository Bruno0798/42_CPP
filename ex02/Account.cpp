/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsousa-d <bsousa-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 08:49:11 by bsousa-d          #+#    #+#             */
/*   Updated: 2024/11/12 09:18:07 by bsousa-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(void)
{

}

Account::Account(int initial_deposit):_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += _amount;
	// _displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" <<_amount << ";created" << std::endl;

}

Account::~Account()
{

}


void	Account::_displayTimestamp(void)
{
	time_t	t;
	struct	tm *tt;
	char	buffer[20];

	time(&t);
	tt = localtime(&t);
	std::strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", tt);
	std::cout << buffer;
}

void Account::displayAccountsInfos()
{
	std::cout	<< "accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
	<< std::endl;
}

void Account::displayStatus() const
{
	std::cout	<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
	<< std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;

	std::cout	<< ";index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< ";deposit:" << deposit
				<< ";amount:" << _amount + deposit
				<< ";nb_deposits:" << _nbDeposits
	<< std::endl;

	_amount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_nbWithdrawals++;

	std::cout	<< "index:" << _accountIndex
				<< ";p_amount:" << _amount
				<< "withdrawal:" << withdrawal
				<< ""

	<< std::endl;

	return true;
}
