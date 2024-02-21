/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:37:58 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:21 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <random>
# include <cstdlib>

class Base
{
	public:
		Base();
		virtual ~Base();
};

Base* Generate(void);
void IdentifyFromPointer(Base* pointer);
void IdentifyFromReference(Base& reference);

#endif