/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:10:03 by felicia           #+#    #+#             */
/*   Updated: 2023/06/06 11:05:37 by felicia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// $>./megaphone "shhhhh... I think the students are asleep..."
// SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
// $>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
// DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
// $>./megaphone
// * LOUD AND UNBEARABLE FEEDBACK NOISE *
// $>

#include <iostream>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	word;
	int	letter;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (word = 1; word < argc; word++)
	{
		for (letter = 0; argv[word][letter] != '\0'; letter++)
		{
			if (argv[word][letter] >= 'a' && argv[word][letter] <= 'z') 
				std::cout << (char)toupper(argv[word][letter]);
			else
				std::cout << argv[word][letter];
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}