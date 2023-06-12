/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 13:05:53 by felicia           #+#    #+#             */
/*   Updated: 2023/06/12 19:45:52 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iomanip>
#include <string>
#include <stdlib.h>
#include <iostream>


class Contact
{
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		int			get_Index(void);
		std::string	get_FirstName(void);
		std::string	get_LastName(void);
		std::string	get_Nickname(void);
		std::string	get_PhoneNumber(void);
		std::string	get_DarkestSecret(void);
		void		set_Index(int);
		void		set_FirstName(std::string);
		void		set_LastName(std::string);
		void		set_Nickname(std::string);
		void		set_PhoneNumber(std::string);
		void		set_DarkestSecret(std::string);
};

class PhoneBook
{
	public:
		Contact	contacts[8];
};