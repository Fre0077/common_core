/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:58 by fre007            #+#    #+#             */
/*   Updated: 2025/05/02 14:57:09 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <algorithm>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template <typename T>
void	swap(T &a, T &b)
{
	T temp;

	temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T &a, const T &b)
{
	if (b <= a)
		return (b);
	else
		return (a);
}

template <typename T>
T	max(const T &a, const T &b)
{
	if (b >= a)
		return (b);
	else
		return (a);
}

#endif