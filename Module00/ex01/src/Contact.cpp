/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:50 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/23 12:47:45 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	index = -1;
	std::cout << GREEN "Constructed contact!\n" OFF;
}

Contact::~Contact(void)
{
	std::cout << RED "Destructed contact!\n" OFF;
}

void	Contact::setIndex(int new_index)
{
	index = new_index;
}

void	Contact::setFirstName(std::string new_first_name)
{
	first_name = new_first_name;
}

void	Contact::setLastName(std::string new_last_name)
{
	last_name = new_last_name;
}

void	Contact::setNickname(std::string new_nickname)
{
	nickname = new_nickname;
}

void	Contact::setPhoneNumber(std::string new_phone_number)
{
	phone_number = new_phone_number;
}

void	Contact::setDarkestSecret(std::string new_darkest_secret)
{
	darkest_secret = new_darkest_secret;
}

int	Contact::getIndex(void)
{
	return (index);
}

std::string	Contact::getFirstName(void)
{
	return (first_name);
}

std::string	Contact::getLastName(void)
{
	return (last_name);
}

std::string	Contact::getNickname(void)
{
	return (nickname);
}

std::string	Contact::getPhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::getDarkestSecret(void)
{
	return (darkest_secret);
}

void	Contact::InputContactInfo(int index)
{
	std::string	user_input;

	setIndex(index);
	std::cout << YELLOW "Enter first name: " OFF;
	std::getline(std::cin, user_input, '\n');
	setFirstName(user_input);
	std::cout << YELLOW "Enter last name: " OFF;
	std::getline(std::cin, user_input, '\n');
	setLastName(user_input);
	std::cout << YELLOW "Enter nickname: " OFF;
	std::getline(std::cin, user_input, '\n');
	setNickname(user_input);
	std::cout << YELLOW "Enter phone number: " OFF;
	std::getline(std::cin, user_input, '\n');
	setPhoneNumber(user_input);
	std::cout << YELLOW "Enter darkest secret: " OFF;
	std::getline(std::cin, user_input, '\n');
	setDarkestSecret(user_input);
}
