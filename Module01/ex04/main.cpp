/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:31:26 by felicia           #+#    #+#             */
/*   Updated: 2023/11/27 16:35:27 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>

void ReplaceString(std::ifstream &input_file, std::ofstream &output_file, char **argv)
{
	std::string	line;
	std::string old_string = argv[2];
	std::string new_string = argv[3];
	std::size_t	position;

	while (std::getline(input_file, line)) 
	{
		position = line.find(old_string);
		while (position != std::string::npos)
		{
			line.erase(position, old_string.length());
			line.insert(position, new_string);
			position = line.find(old_string, position + new_string.length());
		}
		output_file << line;
		if (!input_file.eof())
			output_file << std::endl;
    }
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Incorrect number of arguments, ";
		std::cerr << "try: ./sed <infile> <string to replace> <new string>\n";
		return (EXIT_FAILURE);
	}
	
	const std::string 	filename = argv[1];
	std::ifstream 		input_file(filename);
    if (!input_file) 
	{
        std::cerr << "Error: cannot open input file\n";
        return (EXIT_FAILURE);
    }
    std::ofstream output_file(filename + ".replace");
    if (!output_file) 
	{
        std::cerr << "Error: cannot create output file\n";
		input_file.close();
        return (EXIT_FAILURE);
    }
	
	ReplaceString(input_file, output_file, argv);
	input_file.close();
	output_file.close();
	return (EXIT_SUCCESS);
}