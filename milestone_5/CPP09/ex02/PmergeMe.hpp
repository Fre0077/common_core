/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:36:44 by fde-sant          #+#    #+#             */
/*   Updated: 2025/06/03 18:10:01 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <cmath>
#include <cstddef>

void	sort(std::vector<int> &sequence);

void	sort(std::deque<int> &sequence);

template <typename T>
size_t	getSize(const T &sequence, int recursion)
{
	return (int)sequence.size() / pow(2, recursion);
}

#endif