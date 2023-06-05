/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felicia <felicia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 20:10:03 by felicia           #+#    #+#             */
/*   Updated: 2023/06/05 21:35:36 by felicia          ###   ########.fr       */
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
#include <string>
#include <stdlib.h>

using namespace std;

int	main(int argc, char **argv)
{
	int	word;
	int	letter;

	for (word = 0; word < argc; word++)
	{
		for (letter = 0; argv[word][letter] != '\0'; letter++)
		{
			if (argv[word][letter] >= 'a' && argv[word][letter] <= 'z') 
			{
				cout << argv[word][letter] - 'a';
			}
			else
			{
				cout << argv[word][letter];
			}
		}
	}
	cout << "\n";
	return (1);
}