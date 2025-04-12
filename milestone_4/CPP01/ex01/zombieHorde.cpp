/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:52 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 11:53:24 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];
	
	for (int i = 0; i < N; i++)
		horde[i].setname(name);
	return horde;
}