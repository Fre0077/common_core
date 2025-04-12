/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:54 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 11:36:11 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << "Destroying zombie " << name << "..." << std::endl;
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

void	Zombie::announce()
{
	std::cout << name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}