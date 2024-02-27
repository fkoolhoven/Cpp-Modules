/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:59:38 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/27 18:47:08 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define GREEN		"\033[32m"
# define RED 		"\033[31m"
# define YELLOW		"\033[33m"
# define BOLD		"\033[1m"
# define OFF		"\033[0m"

# include <iostream>
# include <cstdlib>
# include <stack>
# include <string>
# include <sstream>

class RPN
{
	private:
		std::stack<int> stack;
		
	public:
		RPN(std::string input);
		RPN(const RPN& src);
		RPN& operator=(const RPN& src);
		~RPN();

		std::stack<int>& getStack(void);
};

#endif