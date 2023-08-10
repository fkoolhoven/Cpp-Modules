/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/08/10 19:07:24 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

// =====MACROS==================================================================

# define BOLD	"\033[1m"
# define RED	"\033[31m"
# define GREEN 	"\033[32m"
# define YELLOW	"\033[33m"	
# define OFF	"\033[0m"

// =====CLASSES=================================================================

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
		void		set_contact_info(int index);
};

#endif
