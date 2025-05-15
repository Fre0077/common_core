/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:38:02 by fre007            #+#    #+#             */
/*   Updated: 2025/05/15 12:28:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	v.push_back(66);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	try
	{
		std::cout << easyfind(v, 66) << std::endl;
		std::cout << easyfind(v, 5) << std::endl;
		std::cout << easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Element not found" << std::endl;
	}
	return 0;
}