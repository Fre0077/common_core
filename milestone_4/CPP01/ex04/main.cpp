/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:40:05 by fre007            #+#    #+#             */
/*   Updated: 2025/04/09 09:42:16 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

std::string	read_file(std::ifstream &infile)
{
	std::string	ret;
	std::string	add;

	while (std::getline(infile, add))
		ret = ret + add + "\n";
	return ret;
}

void	replace(std::string infile, std::string old, std::string replace, std::string file)
{
	std::ofstream outfile((infile + ".replace").c_str(), std::ios::trunc);

	for (int i = 0; file[i]; i++)
	{
		for (size_t j = 0; j <= old.length(); j++)
		{
			if (old[j] && file[i + j] && old[j] == file[i + j])
				continue;
			else if (!old[j])
			{
				i = i + j - 1;
				outfile << replace;
				break;
			}
			else
			{
				outfile << file[i];
				break;
			}
		}
	}
	outfile.close();
}

int main(int ac, char* av[])
{
	if (ac != 4)
		return 0;
	std::ifstream infile(av[1]);
	std::string file;

	if (!infile.is_open())
		return (std::cout << "Error during file openig" << std::endl, 0);
	file = read_file(infile);
	replace(av[1], av[2], av[3], file);
	infile.close();
	return 0;
}

