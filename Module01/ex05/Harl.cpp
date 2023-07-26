/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:01:03 by felicia           #+#    #+#             */
/*   Updated: 2023/07/26 18:39:19 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is gonna start complaining!\n";
}

Harl::~Harl()
{
	std::cout << "Harl has finished complaining!\n";
}

void	Harl::debug(void)
{
	std::cout << GREEN"I love having extra bacon for my "
					"7XL-double-cheese-triple-pickle-specialketchup "
					"burger. I really do!\n" << OFF;
}

void	Harl::info(void)
{
	std::cout << BLUE"I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger! If you "
					"did, I wouldn’t be asking for more!\n" << OFF;
}

void	Harl::warning(void)
{
	std::cout << YELLOW"I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years whereas you started "
					"working here since last month.\n" << OFF;
}

void	Harl::error(void)
{
	std::cout << RED"This is unacceptable! I want to speak to "
					"the manager now.\n" << OFF;
}

void	Harl::complain(std::string level)
{
	void (Harl::*functions[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
	{
    	if (levels[i] == level)
			(this->*functions[i])();
	}
}
