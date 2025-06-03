/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:32:22 by fre007            #+#    #+#             */
/*   Updated: 2025/05/26 10:44:44 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED "\033[0;31m"
# define END "\033[0m"

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <map>
# include <string>
# include <cctype>
# include <iomanip>

std::string trim(const std::string& str);
bool split(const std::string& s, char delimiter, std::string parts[2]);
int convertData(const std::string& data);
bool checkInput(const std::string& input);
bool parseDate(const std::string& str, int& y, int& m, int& d);

class BitcoinExchange
{
private:
	std::map<int, double>	data;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& copy);

	double	searchValue(std::string input);
};

#endif
