/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:55:35 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 16:46:32 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanA
{
private:
	std::string	name;
	Weapon		&weapon;

public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	setWeapon(Weapon weapon);
	void	attack() const;
};