/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:50 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/10 19:04:17 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
	index = -1;
	std::cout << GREEN"Constructed contact!\n" << OFF;
}

Contact::~Contact(void)
{
	std::cout << RED"Destructed contact!\n" << OFF;
}

void	Contact::set_Index(int newIndex)
{
	index = newIndex;
}

void	Contact::set_FirstName(std::string new_FirstName)
{
	first_name = new_FirstName;
}

void	Contact::set_LastName(std::string new_LastName)
{
	last_name = new_LastName;
}

void	Contact::set_Nickname(std::string new_Nickname)
{
	nickname = new_Nickname;
}

void	Contact::set_PhoneNumber(std::string new_PhoneNumber)
{
	phone_number = new_PhoneNumber;
}

void	Contact::set_DarkestSecret(std::string new_DarkestSecret)
{
	darkest_secret = new_DarkestSecret;
}

int	Contact::get_Index(void)
{
	return (index);
}

std::string	Contact::get_FirstName(void)
{
	return (first_name);
}

std::string	Contact::get_LastName(void)
{
	return (last_name);
}

std::string	Contact::get_Nickname(void)
{
	return (nickname);
}

std::string	Contact::get_PhoneNumber(void)
{
	return (phone_number);
}

std::string	Contact::get_DarkestSecret(void)
{
	return (darkest_secret);
}

void	Contact::set_contact_info(int index)
{
	std::string	user_input;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	set_Index(index);
	std::cout << YELLOW"Enter first name: " << OFF;
	std::getline(std::cin, user_input, '\n');
	set_FirstName(user_input);
	std::cout << YELLOW"Enter last name: " << OFF;
	std::getline(std::cin, user_input, '\n');
	set_LastName(user_input);
	std::cout << YELLOW"Enter nickname: " << OFF;
	std::getline(std::cin, user_input, '\n');
	set_Nickname(user_input);
	std::cout << YELLOW"Enter phone number: " << OFF;
	std::getline(std::cin, user_input, '\n');
	set_PhoneNumber(user_input);
	std::cout << YELLOW"Enter darkest secret: " << OFF;
	std::getline(std::cin, user_input, '\n');
	set_DarkestSecret(user_input);
}
