/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:56:01 by felicia           #+#    #+#             */
/*   Updated: 2023/06/26 19:24:32 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit(int deposit)
{
	Account::_amount += deposit;
	Account::_nbDeposits++;
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";deposits:" << Account::_nbDeposits;
	std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_amount -= withdrawal;
	Account::_nbWithdrawals++;
	std::cout << "index:" << Account::_accountIndex;
	std::cout << ";amount:" << Account::_amount;
	std::cout << ";deposits:" << Account::_nbDeposits;
	std::cout << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (true);
}

void	Account::displayAccountsInfos(void)
{
	//std::cout << "index:" << Account::_accountIndex << ";amount:";
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int test)
{
	std::cout << "\nCONSTRUCTOR\n";
}

Account::~Account()
{
	std::cout << "\nDESTRUCTOR\n";;
}

void	Account::displayStatus(void) const
{
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}
