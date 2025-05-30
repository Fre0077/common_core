/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:55:31 by fre007            #+#    #+#             */
/*   Updated: 2025/05/30 18:57:42 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
//==============================================================================
//COSTRUCTOR/DESTRUCTOR=========================================================
//==============================================================================
RPN::RPN(std::string input)
{
	std::vector<std::string>	divide = split(input, ' ');
	for (size_t i = divide.size(); i > 0; i--)
	{
		if (isNum(divide[i - 1]) || isSign(divide[i - 1]))
			this->all.push(divide[i - 1]);
		else
			throw wrongArg();
		if (this->all.size() > 10)
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
	if (check == "+" || check == "-" || check == "*" || check == "/")
		return 1;
	return 0;
}

int isNum(const std::string& str)
{
    if (str.empty())
        return 0;
    for (size_t i = 0; i < str.length(); ++i) {
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

std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void	RPN::op()
{
	if (this->all.top() == "-")
	{
		int num;
		num = this->number.top();
		this->number.pop();
		num = this->number.top() - num;
		this->number.pop();
		this->number.push(num);
	}
	else if (this->all.top() == "+")
	{
		int num;
		num = this->number.top();
		this->number.pop();
		num = this->number.top() + num;
		this->number.pop();
		this->number.push(num);
	}
	else if (this->all.top() == "*")
	{
		int num;
		num = this->number.top();
		this->number.pop();
		num = this->number.top() * num;
		this->number.pop();
		this->number.push(num);
	}
	else if (this->all.top() == "/")
	{
		int num;
		num = this->number.top();
		this->number.pop();
		num = this->number.top() / num;
		this->number.pop();
		this->number.push(num);
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
			op ();
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