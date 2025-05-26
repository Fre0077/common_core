/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:23:28 by fre007            #+#    #+#             */
/*   Updated: 2025/05/26 11:05:42 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc [filename]" << std::endl;
		return 1;
	}
	if (std::string(av[1]) == "empty")
	{
		std::cerr << "Invalid file" << std::endl;
		return 1;
	}
	BitcoinExchange	btc;
	std::ifstream	file(av[1]);
	std::string		line, date, quantity;
	double			ret;
	while(std::getline(file, line))
	{
		ret = btc.searchValue(line);
		if (ret == -1)
			continue;
		date = trim(line.substr(0, line.find('|')));
		quantity = trim(line.substr(line.find('|') + 1));
		std::cout << date << " => " << quantity << " = " << ret << std::endl;
	}
	return 0;
}