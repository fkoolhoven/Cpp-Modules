/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoolhov <fkoolhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:31:26 by felicia           #+#    #+#             */
/*   Updated: 2023/11/28 12:33:20 by fkoolhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

void ReplaceString(std::ifstream &input_file, std::ofstream &output_file, char **argv)
{
    std::stringstream buffer;
    buffer << input_file.rdbuf();

    std::string content = buffer.str();
    std::string old_string = argv[2];
    std::string new_string = argv[3];

    std::size_t position = content.find(old_string);

    while (position != std::string::npos)
	{
        content.erase(position, old_string.length());
        content.insert(position, new_string);
        position = content.find(old_string, position + new_string.length());
    }
    output_file << content;
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