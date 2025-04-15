/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:21:02 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 11:02:45 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
DiamondTrap::DiamondTrap() : ClapTrap()
{
	std::cout << "created default DiamondTrap" << std::endl;
	this->name = "an ordinary DiamondTrap";
	FragTrap::hitPoint = 100;
	ScavTrap::energyPoint = 50;
	ScavTrap::attackPoint = 30;
	this->guardGate = false;
}

DiamondTrap::DiamondTrap(DiamondTrap const& copy) : ScavTrap(copy)
{
	std::cout << "copy DiamondTrap" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "created default DiamondTrap" << std::endl;
	this->name = name + "_clap_name";
	FragTrap::hitPoint = 100;
	ScavTrap::energyPoint = 50;
	ScavTrap::attackPoint = 30;
	this->guardGate = false;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "destried DiamondTrap" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& copy)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	{
		this->name = copy.name;
		this->hitPoint = copy.hitPoint;
		this->energyPoint = copy.energyPoint;
		this->attackPoint = copy.attackPoint;
		this->guardGate = copy.guardGate;
	}
	return *this;
}
//==============================================================================
//METHOD========================================================================
//==============================================================================
void	DiamondTrap::_guardGate(void)
{
	if (this->hitPoint > 0 && this->guardGate == false)
		this->guardGate = true;
	else if (this->hitPoint > 0 && this->guardGate == true)
		this->guardGate = false;
	else
		std::cout << "DiamondTrap " << this->name << " is death!" << std::endl;
}

void	DiamondTrap::highFivesGuys(void)
{
	std::cout << "DiamondTrap " << this->name << ": You want a high five?\n*WHAMM*\nHere you go." << std::endl;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I'm " << this->name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "DiamondTrap " << this->name << " attacks " << target
				<< ", causing " << this->attackPoint << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else if (this->energyPoint == 0)
		std::cout << "DiamondTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "DiamondTrap " << this->name << " is death!" << std::endl;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > amount)
	{
		std::cout << "DiamondTrap " << this->name << " receive " << amount
				<< " damage!" << std::endl;
		this->hitPoint -= amount;
	}
	else if (this->hitPoint > 0)
	{
		std::cout << "DiamondTrap " << this->name << " receive " << amount
				<< " damage and die!" << std::endl;
		this->hitPoint = 0;
	}
	else
		std::cout << "DiamondTrap " << this->name << " is death!" << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "DiamondTrap " << this->name << " got repaired of " << amount
				<< " hitpoint " << std::endl;
		this->energyPoint--;
		this->hitPoint += amount;
	}
	else if (this->energyPoint == 0)
		std::cout << "DiamondTrap " << this->name << " is out of energy!" << std::endl;
	else if (this->energyPoint == 0)
		std::cout << "DiamondTrap " << this->name << " is death!" << std::endl;
}
