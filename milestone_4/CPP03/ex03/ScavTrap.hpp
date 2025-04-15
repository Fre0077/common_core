/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 09:42:59 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 10:47:21 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(ScavTrap const& copy);
	ScavTrap(std::string name);
	virtual	~ScavTrap();
	ScavTrap&	operator=(ScavTrap const& copy);
	void	_guardGate(void);
	void 	attack(const std::string& target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

protected:
	bool	guardGate;
};