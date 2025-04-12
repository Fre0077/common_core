/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:46:34 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 16:45:59 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon()
{
	std::cout << "destroing weapon" << std::endl;
}

std::string	Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}