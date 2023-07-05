/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/07/05 13:39:09 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
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
		Contact(void);
		~Contact(void);
		void		set_Index(int new_Index);
		int			get_Index(void);
		void		set_FirstName(std::string new_FirstName);
		std::string	get_FirstName(void);
		void		set_LastName(std::string new_LastName);
		std::string	get_LastName(void);
		void		set_Nickname(std::string new_Nickname);
		std::string	get_Nickname(void);
		void		set_PhoneNumber(std::string new_PhoneNumber);
		std::string	get_PhoneNumber(void);
		void		set_DarkestSecret(std::string new_DarkestSecret);
		std::string	get_DarkestSecret(void);
		void		add_new_contact(int index);
};

#endif
