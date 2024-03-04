/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:03:14 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/03/04 15:28:00 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string input)
{
	bool straggler = false;
	bool error = false;
	std::istringstream input_stream(input);
	std::string line;

	while (!error && std::getline(input_stream, line, ' '))
	{
		try
		{
			stack.push(std::stoi(line));
			if (stack.size() > 2)
			{
				std::cerr << RED "Invalid input\n" OFF;
				error = true;
			}
			straggler = true;
		}
		catch (const std::exception& exception)
		{
			if (line.length() != 1 || stack.size() < 2)
			{
				std::cerr << RED "Invalid input\n" OFF;
				error = true;
			}
			else
			{
				straggler = false;
				int second = stack.top();
				stack.pop();
				int first = stack.top();
				stack.pop();
				
				switch (line[0])
				{
					case '+':
						stack.push(first + second);
						break;
					case '-':
						stack.push(first - second);
						break;
					case '*':
						stack.push(first * second);
						break;
					case '/':
						stack.push(first / second);
						break;
					default:
						std::cerr << RED "Invalid input\n" OFF;
						error = true;
				}
			}
		}
	}
	
	if (straggler)
		std::cerr << RED "Invalid input\n" OFF;
	else if (!error)
		std::cout << "Result: " << stack.top() << std::endl;
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN& src)
{
	this->stack = src.stack;
	return (*this);
}

RPN::~RPN() { }

std::stack<int>& RPN::getStack(void)
{
	return (this->stack);
}