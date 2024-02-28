/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:50:15 by fkoolhov          #+#    #+#             */
/*   Updated: 2024/02/28 17:55:29 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Here are some additional guidelines on the information you should display line by line
// on the standard output:
// • On the first line you must display an explicit text followed by the unsorted positive
// integer sequence.
// • On the second line you must display an explicit text followed by the sorted positive
// integer sequence.
// • On the third line you must display an explicit text indicating the time used by
// your algorithm by specifying the first container used to sort the positive integer
// sequence.
// • On the last line you must display an explicit text indicating the time used by
// your algorithm by specifying the second container used to sort the positive integer
// sequence.

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./pmergeme <positive integer sequence>\n";
		return (EXIT_FAILURE);
	}

	
	return (EXIT_SUCCESS);
}