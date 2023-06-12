/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:35:04 by felicia           #+#    #+#             */
/*   Updated: 2023/06/12 19:54:35 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

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
