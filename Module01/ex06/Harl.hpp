/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:01:01 by felicia           #+#    #+#             */
/*   Updated: 2023/07/27 14:46:50 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

#define RED		"\033[31m"
#define GREEN 	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"	
#define OFF		"\033[0m"

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
