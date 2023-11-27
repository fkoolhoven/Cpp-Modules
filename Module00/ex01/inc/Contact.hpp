/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:47:19 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/11/27 15:34:56 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <limits>

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
	
		void		setIndex(int new_Index);
		int			getIndex(void);
		void		setFirstName(std::string new_FirstName);
		std::string	getFirstName(void);
		void		setLastName(std::string new_LastName);
		std::string	getLastName(void);
		void		setNickname(std::string new_Nickname);
		std::string	getNickname(void);
		void		setPhoneNumber(std::string new_PhoneNumber);
		std::string	getPhoneNumber(void);
		void		setDarkestSecret(std::string new_DarkestSecret);
		std::string	getDarkestSecret(void);
		void		InputContactInfo(int index);
};

#endif
