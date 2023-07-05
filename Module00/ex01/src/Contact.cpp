/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:44:50 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/05 13:36:11 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
	std::cout << "\nConstructed contact!\n";
	index = -1;
}

Contact::~Contact(void)
{
	std::cout << "\nDestructed contact!\n";
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

void	Contact::add_new_contact(int i)
{
	std::string	user_input;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	set_Index(i);
	std::cout << "Enter first name:\n";
	std::getline(std::cin, user_input, '\n');
	set_FirstName(user_input);
	std::cout << "Enter last name:\n";
	std::getline(std::cin, user_input, '\n');
	set_LastName(user_input);
	std::cout << "Enter nickname:\n";
	std::getline(std::cin, user_input, '\n');
	set_Nickname(user_input);
	std::cout << "Enter phone number:\n";
	std::getline(std::cin, user_input, '\n');
	set_PhoneNumber(user_input);
	std::cout << "Enter darkest secret:\n";
	std::getline(std::cin, user_input, '\n');
	set_DarkestSecret(user_input);
}
