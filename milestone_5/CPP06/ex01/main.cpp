/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesco <francesco@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:11:31 by francesco         #+#    #+#             */
/*   Updated: 2025/04/24 12:17:13 by francesco        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serialization.hpp"

int main() {
	Data original;
	original.str = "ciao";
	original.n = 42;

	unsigned long raw = Serialization::serialize(&original);
	Data* copy = Serialization::deserialize(raw);

	std::cout << "Original: " << original.str << ", " << original.n << std::endl;
	std::cout << "Copy: " << copy->str << ", " << copy->n << std::endl;

	return 0;
}