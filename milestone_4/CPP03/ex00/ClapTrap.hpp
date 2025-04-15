/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:39:02 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/14 09:14:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(std::string n);
	ClapTrap(ClapTrap const& copy);
	ClapTrap(std::string n, unsigned int h, unsigned int e, unsigned int a);
	ClapTrap& operator=(ClapTrap const& copy);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

private:
	std::string		name;
	unsigned int	hitPoint;
	unsigned int	energyPoint;
	unsigned int	attackPoint;
};