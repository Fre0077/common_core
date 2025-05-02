/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:42:58 by fre007            #+#    #+#             */
/*   Updated: 2025/05/02 15:37:06 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <algorithm>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template <typename T, typename F>
void iter(T *array, size_t len, F f)
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

#endif