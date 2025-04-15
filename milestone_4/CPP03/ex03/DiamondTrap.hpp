/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:58:58 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 10:23:50 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &src);
	void	attack(const std::string &target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);
	void	whoAmI(void);
	void	_guardGate(void);
	void	highFivesGuys(void);

private:
	std::string name;
};