/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:10:03 by felicia           #+#    #+#             */
/*   Updated: 2023/08/10 18:32:58 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	word;
	int	letter;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (word = 1; word < argc; word++)
		{
			for (letter = 0; argv[word][letter] != '\0'; letter++)
					std::cout << (char)toupper(argv[word][letter]);
		}		
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}