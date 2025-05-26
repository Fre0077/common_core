/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:55:36 by fre007            #+#    #+#             */
/*   Updated: 2025/05/26 12:19:06 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

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

class RPN
{
private:
	std::stack<int>			number;
	std::stack<std::string>	sign;
	RPN();
public:
	RPN(std::string input);
	RPN(RPN const& copy);
	~RPN();
};

#endif