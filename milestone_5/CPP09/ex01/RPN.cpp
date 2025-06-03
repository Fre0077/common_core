/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:55:31 by fre007            #+#    #+#             */
/*   Updated: 2025/05/31 08:39:27 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
RPN::RPN(std::string input)
{
	const int MAX_TOKENS = 10;
	std::string tokens[MAX_TOKENS];
	int count = split(input, ' ', tokens, MAX_TOKENS);

	for (int i = count - 1; i >= 0; --i)
	{
		if (isNum(tokens[i]) || isSign(tokens[i]))
			this->all.push(tokens[i]);
		else
			throw wrongArg();
		if ((int)this->all.size() > MAX_TOKENS)
			throw tooManyArg();
	}
}

RPN::RPN(RPN const& copy) : number(copy.number), all(copy.all) {}

RPN::~RPN() {}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
RPN& RPN::operator=(RPN const& copy)
{
	if (this == &copy)
		return *this;
	number = copy.number;
	all = copy.all;
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
int	isSign(const std::string& check)
{
	return (check == "+" || check == "-" || check == "*" || check == "/");
}

int isNum(const std::string& str)
{
	if (str.empty())
		return 0;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]))
			return 0;
	}
	return 1;
}

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

int split(const std::string& s, char delimiter, std::string tokens[], int maxTokens)
{
	std::istringstream tokenStream(s);
	std::string token;
	int count = 0;
	while (std::getline(tokenStream, token, delimiter) && count < maxTokens)
	{
		tokens[count++] = token;
	}
	return count;
}

void	RPN::op()
{
	int num = this->number.top();
	this->number.pop();

	if (this->number.empty())
		throw wrongArg();

	int left = this->number.top();
	this->number.pop();

	if (this->all.top() == "-")
		this->number.push(left - num);
	else if (this->all.top() == "+")
		this->number.push(left + num);
	else if (this->all.top() == "*")
		this->number.push(left * num);
	else if (this->all.top() == "/")
	{
		if (num == 0)
			throw wrongArg();
		this->number.push(left / num);
	}

	this->all.pop();
}

void	RPN::calculate()
{
	size_t dim = this->all.size();
	for (size_t i = 0; i < dim; i++)
	{
		if (isNum(this->all.top()))
		{
			std::stringstream ss(this->all.top());
			int num;
			ss >> num;
			this->number.push(num);
			this->all.pop();
		}
		else if (isSign(this->all.top()) && this->number.size() >= 2)
			op();
		else
			throw wrongArg();
	}
	if (this->number.size() != 1)
		throw wrongArg();
	else
		this->final = this->number.top();
	this->number.pop();
}

int	RPN::getNum()
{
	return this->final;
}
