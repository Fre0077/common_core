/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:08:47 by fde-sant          #+#    #+#             */
/*   Updated: 2025/05/15 12:22:32 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <climits>
# include <iomanip>
# include <set>

template<typename T>
int	easyfind(T &container, int n)
{
	if (std::find(container.begin(), container.end(), n) == container.end())
		throw std::exception();
	return *std::find(container.begin(), container.end(), n);
}

#endif