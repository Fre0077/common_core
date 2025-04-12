/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:43:56 by fre007            #+#    #+#             */
/*   Updated: 2025/04/08 11:48:49 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <cctype>
# include <string>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	~Zombie();
	void announce(void);
	void setname(std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif