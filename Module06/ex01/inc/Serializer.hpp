/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:10:40 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:08 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# define GREEN	"\033[32m"
# define RED 	"\033[31m"
# define YELLOW	"\033[33m"
# define BOLD	"\033[1m"
# define OFF	"\033[0m"

# include <iostream>
# include <cstdlib>

struct Data
{
	std::string first_name;
	std::string last_name;
	int			age;
};

class Serializer
{
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer& instance);	
		Serializer& operator=(const Serializer& instance);	

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif