/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:28:54 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 09:38:08 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "created default FragTrap" << std::endl;
	this->name = "an ordinary FragTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackPoint = 20;
}

FragTrap::FragTrap(FragTrap const& copy) : ClapTrap(copy)
{
	std::cout << "copy FragTrap" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "created default FragTrap" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackPoint = 20;
}

FragTrap::~FragTrap()
{
	std::cout << "destried FragTrap" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
FragTrap&	FragTrap::operator=(FragTrap const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoint = copy.hitPoint;
		this->energyPoint = copy.energyPoint;
		this->attackPoint = copy.attackPoint;
	}
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << ": You want a high five?\n*WHAMM*\nHere you go." << std::endl;
}


void	FragTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "FragTrap " << this->name << " attacks " << target
				<< ", causing " << this->attackPoint << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else if (this->energyPoint == 0)
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "FragTrap " << this->name << " is death!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > amount)
	{
		std::cout << "FragTrap " << this->name << " receive " << amount
				<< " damage!" << std::endl;
		this->hitPoint -= amount;
	}
	else if (this->hitPoint > 0)
	{
		std::cout << "FragTrap " << this->name << " receive " << amount
				<< " damage and die!" << std::endl;
		this->hitPoint = 0;
	}
	else
		std::cout << "FragTrap " << this->name << " is death!" << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "FragTrap " << this->name << " got repaired of " << amount
				<< " hitpoint " << std::endl;
		this->energyPoint--;
		this->hitPoint += amount;
	}
	else if (this->energyPoint == 0)
		std::cout << "FragTrap " << this->name << " is out of energy!" << std::endl;
	else if (this->energyPoint == 0)
		std::cout << "FragTrap " << this->name << " is death!" << std::endl;
}
