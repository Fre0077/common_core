/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:42:59 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 10:06:24 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const& copy);
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap&	operator=(ScavTrap const& copy);
	void	_guardGate(void);
	void 	attack(const std::string& target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

private:
	bool	guardGate;
};