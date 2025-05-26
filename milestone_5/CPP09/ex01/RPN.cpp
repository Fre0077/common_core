/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:55:31 by fre007            #+#    #+#             */
/*   Updated: 2025/05/26 12:19:43 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
RPN::RPN(std::string input)
{
	
}

RPN::RPN(RPN const& copy) : number(copy.number), sign(copy.sign) {}

RPN::~RPN() {}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
RPN& RPN::operator=(RPN const& copy)
{
	if (this == &copy)
	return *this;
	number = copy.number;
	sign = copy.sign;
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

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

std::vector<int> splitInt(const std::string& s, char delimiter)
{
	std::vector<int> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(atoi(token.c_str()));
	return tokens;
}

bool isLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int getDaysInMonth(int year, int month)
{
	static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		return 29;
	return days[month - 1];
}

int convertData(std::string data)
{
	std::vector<int>	value;
	int							ret = 0;
	value = splitInt(data, '-');
	if (value[0] < 2009 || value[0] > 2022 || value[1] < 1 || value[1] > 12 || value[2] < 1 || value[2] > getDaysInMonth(value[0], value[1]))
		return -1;
	ret += value[0] * 365;
	ret += (value[0] / 4);
	for(int i = 1; i < value[1]; i++)
		ret += getDaysInMonth(value[0], i);
	ret += value[2];
	return ret;
}

bool checkInput(std::string input)
{
	std::string	date;
	std::string	quantity;
	size_t		i = 0;
	date = trim(input.substr(0, input.find('|')));
	quantity = trim(input.substr(input.find('|') + 1));
	for(;i < 4; i++)
		if (!std::isdigit(date[i]))
			return true;
	if (date[i++] != '-')
		return true;
	for(;i < 7; i++)
		if (!std::isdigit(date[i]))
			return true;
	if (date[i++] != '-')
		return true;
	for(;i < 10; i++)
		if (!std::isdigit(date[i]))
			return true;
	i = 0;
	if (!std::isdigit(quantity[i]))
		return true;
	for(;std::isdigit(quantity[i]); i++)
		;
	if (quantity[i++] != '.')
		return true;
	if (!std::isdigit(quantity[i]))
		return true;
	for(;i < quantity.length(); i++)
		if (!std::isdigit(quantity[i]))
			return true;
	return false;
}

double RPN::searchValue(std::string input)
{
	std::vector<std::string>	value;
	int							date;
	double						quantity;

	if(checkInput(input))
		return (std::cout << RED "Error: bad input => " << input << "" END << std::endl, -1);
	value = split(input, '|');
	date = convertData(trim(value[0]));
	if (date == -1)
		return (std::cout << RED "Error: bad input => " << input << "" END << std::endl, -1);
	quantity = std::atof(trim(value[1]).c_str());
	if (quantity < 0)
		return (std::cout << RED "Error: not a positive number." END << std::endl, -1);
	else if (quantity > 1000)
		return (std::cout << RED "Error: too large a number." END << std::endl, -1);
	for(; this->data.find(date) == this->data.end(); date--)
		;
	return (quantity * this->data[date]);
}