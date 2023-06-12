/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:13:28 by felicia           #+#    #+#             */
/*   Updated: 2023/06/12 19:53:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

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
