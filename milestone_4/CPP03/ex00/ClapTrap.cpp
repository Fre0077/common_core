/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:38:37 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/14 09:16:17 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
//==============================================================================
//COSTRUCTOR/ESTRUCTOR==========================================================
//==============================================================================
ClapTrap::ClapTrap()
{
	//std::cout << "created default ClapTrap" << std::endl;
	this->name = "an ordinary claptrap";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackPoint = 0;
}

ClapTrap::ClapTrap(std::string n)
{
	//std::cout << "created default ClapTrap" << std::endl;
	this->name = n;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackPoint = 0;
}

ClapTrap::ClapTrap(std::string n, unsigned int h, unsigned int e, unsigned int a)
{
	//std::cout << "created value ClapTrap" << std::endl;
	this->name = n;
	this->hitPoint = h;
	this->energyPoint = e;
	this->attackPoint = a;
}

ClapTrap::ClapTrap(ClapTrap const& copy)
{
	//std::cout << "copy ClapTrap" << std::endl;
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackPoint = copy.attackPoint;
}

ClapTrap::~ClapTrap()
{
	//std::cout << "destried ClapTrap" << std::endl;
}
//==============================================================================
//OPERATOR======================================================================
//==============================================================================
ClapTrap&	ClapTrap::operator=(ClapTrap const& copy)
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
void	ClapTrap::attack(const std::string& target)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target
				<< ", causing " << this->attackPoint << " points of damage!" << std::endl;
		this->energyPoint--;
	}
	else if (this->energyPoint == 0)
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is death!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint > amount)
	{
		std::cout << "ClapTrap " << this->name << " receive " << amount
				<< " damage!" << std::endl;
		this->hitPoint -= amount;
	}
	else if (this->hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " receive " << amount
				<< " damage and die!" << std::endl;
		this->hitPoint = 0;
	}
	else
		std::cout << "ClapTrap " << this->name << " is death!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoint > 0 && this->hitPoint > 0)
	{
		std::cout << "ClapTrap " << this->name << " got repaired of " << amount
				<< " hitpoint " << std::endl;
		this->energyPoint--;
		this->hitPoint += amount;
	}
	else if (this->energyPoint == 0)
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
	else if (this->energyPoint == 0)
		std::cout << "ClapTrap " << this->name << " is death!" << std::endl;
}