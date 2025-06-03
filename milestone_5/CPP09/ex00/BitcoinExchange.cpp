/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 21:22:22 by fre007            #+#    #+#             */
/*   Updated: 2025/05/31 08:39:32 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string parts[2];

	if (!file.is_open())
		std::cout << RED "Error: could not open file." END << std::endl;
	else
	{
		while (std::getline(file, line))
		{
			if (split(line, ',', parts))
			{
				int date = convertData(parts[0]);
				double rate = std::atof(parts[1].c_str());
				if (date != -1)
					this->data[date] = rate;
			}
		}
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : data(copy.data) {}

BitcoinExchange::~BitcoinExchange() {}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	if (this == &copy)
		return *this;
	this->data = copy.data;
	return *this;
}

//==============================================================================
//METHOD========================================================================
//==============================================================================
std::string trim(const std::string& str)
{
	size_t start = 0;
	while (start < str.length() && std::isspace(str[start]))
		start++;
	size_t end = str.length();
	while (end > start && std::isspace(str[end - 1]))
		end--;
	return str.substr(start, end - start);
}

bool split(const std::string& s, char delimiter, std::string parts[2])
{
	size_t pos = s.find(delimiter);
	if (pos == std::string::npos)
		return false;
	parts[0] = s.substr(0, pos);
	parts[1] = s.substr(pos + 1);
	return true;
}

bool parseDate(const std::string& str, int& year, int& month, int& day)
{
	if (str.length() != 10 || str[4] != '-' || str[7] != '-')
		return false;

	year = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 2).c_str());
	day = std::atoi(str.substr(8, 2).c_str());

	return true;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getDaysInMonth(int year, int month)
{
	static const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeapYear(year))
		return 29;
	return days[month - 1];
}

int convertData(const std::string& data)
{
	int year, month, day;
	if (!parseDate(data, year, month, day))
		return -1;

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > getDaysInMonth(year, month))
		return -1;

	int days = year * 365 + year / 4;
	for (int i = 1; i < month; ++i)
		days += getDaysInMonth(year, i);
	days += day;
	return days;
}

bool checkInput(const std::string& input)
{
	std::string parts[2];
	if (!split(input, '|', parts))
		return true;

	std::string date = trim(parts[0]);
	std::string quantity = trim(parts[1]);

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return true;

	for (size_t i = 0; i < date.length(); ++i)
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return true;

	bool dotSeen = false;
	int digits = 0;
	for (size_t i = 0; i < quantity.length(); ++i)
	{
		if (quantity[i] == '.')
		{
			if (dotSeen)
				return true;
			dotSeen = true;
		}
		else if (!isdigit(quantity[i]))
			return true;
		else
			digits++;
	}
	return digits == 0;
}

double BitcoinExchange::searchValue(std::string input)
{
	std::string parts[2];

	if (checkInput(input))
	{
		std::cout << RED "Error: bad input => " << input << END << std::endl;
		return -1;
	}

	split(input, '|', parts);
	int date = convertData(trim(parts[0]));
	if (date == -1)
	{
		std::cout << RED "Error: bad input => " << input << END << std::endl;
		return -1;
	}

	double quantity = std::atof(trim(parts[1]).c_str());
	if (quantity < 0)
	{
		std::cout << RED "Error: not a positive number." END << std::endl;
		return -1;
	}
	else if (quantity > 1000)
	{
		std::cout << RED "Error: too large a number." END << std::endl;
		return -1;
	}

	while (this->data.find(date) == this->data.end() && date > 0)
		date--;

	return quantity * this->data[date];
}
