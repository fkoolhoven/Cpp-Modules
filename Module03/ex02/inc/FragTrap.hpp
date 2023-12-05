/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:00:40 by fkoolhov          #+#    #+#             */
/*   Updated: 2023/12/05 10:55:26 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(); 
		FragTrap(std::string init_name); 
		FragTrap(const FragTrap &original); 
		//FragTrap&	operator=(const FragTrap &original);
		~FragTrap();

		void HighFivesGuys(void);
};

#endif