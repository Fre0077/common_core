/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:26:35 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/15 10:06:14 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap : ClapTrap
{
public:
	FragTrap();
	FragTrap(FragTrap const& copy);
	FragTrap(std::string name);
	~FragTrap();
	FragTrap&	operator=(FragTrap const& copy);
	void	highFivesGuys(void);
	void 	attack(const std::string& target);
	void 	takeDamage(unsigned int amount);
	void 	beRepaired(unsigned int amount);

private:
};