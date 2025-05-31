/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 08:40:03 by fde-sant          #+#    #+#             */
/*   Updated: 2025/05/31 08:40:05 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main ( int ac, char **av )
{
	if (ac == 1)
	{
		std::cout << "Usage: ./pmerge [numbers]" << std::endl;
		return 1;
	}
	if (ac == 2)
	{
		std::cout << "Please enter more than one number" << std::endl;
		return 1;
	}
	SortDeez sort(av + 1);
	return 0;
}