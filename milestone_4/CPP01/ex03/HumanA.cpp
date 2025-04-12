/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:50:03 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 16:46:35 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {}

HumanA::~HumanA()
{
	std::cout << "destroing HumanA" << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}

void	HumanA::attack() const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}