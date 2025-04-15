/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 08:19:08 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 09:33:25 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "created default ScavTrap" << std::endl;
	this->name = "an ordinary ScavTrap";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackPoint = 20;
	this->guardGate = false;
}

ScavTrap::ScavTrap(ScavTrap const& copy) : ClapTrap(copy)
{
	std::cout << "copy ScavTrap" << std::endl;
	this->guardGate = copy.guardGate;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "created default ScavTrap" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackPoint = 20;
	this->guardGate = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << "destried ScavTrap" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
ScavTrap&	ScavTrap::operator=(ScavTrap const& copy)
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
void	ScavTrap::_guardGate(void)
{
	if (this->hitPoint > 0 && this->guardGate == false)
		this->guardGate = true;
	else if (this->hitPoint > 0 && this->guardGate == true)
		this->guardGate = false;
	else
		std::cout << "ScavTrap " << this->name << " is death!" << std::endl;
}


void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target
				<< ", causing " << this->attackPoint << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else if (this->energyPoint == 0)
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is death!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > amount)
	{
		std::cout << "ScavTrap " << this->name << " receive " << amount
				<< " damage!" << std::endl;
		this->hitPoint -= amount;
	}
	else if (this->hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->name << " receive " << amount
				<< " damage and die!" << std::endl;
		this->hitPoint = 0;
	}
	else
		std::cout << "ScavTrap " << this->name << " is death!" << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ScavTrap " << this->name << " got repaired of " << amount
				<< " hitpoint " << std::endl;
		this->energyPoint--;
		this->hitPoint += amount;
	}
	else if (this->energyPoint == 0)
		std::cout << "ScavTrap " << this->name << " is out of energy!" << std::endl;
	else if (this->energyPoint == 0)
		std::cout << "ScavTrap " << this->name << " is death!" << std::endl;
}
