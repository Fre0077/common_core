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

# include <algorithm>
# include <iostream>
# include <cstdlib>
# include <climits>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cctype>
# include <vector>
# include <stack>
# include <set>
# include <map>

std::string trim(const std::string& str);
std::vector<std::string> split(const std::string& s, char delimiter);
int convertData(std::string data);

class BitcoinExchange
{
private:
	std::map<int, double>	data;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &copy);
	~BitcoinExchange();
	BitcoinExchange& operator=(BitcoinExchange const& copy);

	double		searchValue(std::string input);
};

#endif