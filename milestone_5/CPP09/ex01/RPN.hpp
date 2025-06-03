/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:55:36 by fre007            #+#    #+#             */
/*   Updated: 2025/05/31 10:55:00 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RED "\033[0;31m"
# define END "\033[0m"

# include <iostream>
# include <cstdlib>
# include <climits>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <cctype>
# include <stack>

int	isSign(const std::string& check);
int isNum(const std::string& str);
std::string trim(const std::string& str);
int split(const std::string& s, char delimiter, std::string tokens[], int maxTokens);

class RPN
{
private:
	std::stack<int>			number;
	std::stack<std::string>	all;
	int						final;
	RPN();

public:
	RPN(std::string input);
	RPN(RPN const& copy);
	~RPN();
	RPN&	operator=(RPN const& copy);
	void	op();
	void	calculate();
	int		getNum();

	class wrongArg : public std::exception {
	public:
		const char* what() const throw() {
			return "Wrong argument!!!";
		}
	};
	class tooManyArg : public std::exception {
	public:
		const char* what() const throw() {
			return "Too many arguments!!!";
		}
	};
	class noRet : public std::exception {
	public:
		const char* what() const throw() {
			return "No return value found!!!";
		}
	};
};

#endif
