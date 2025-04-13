/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:03:16 by fre007            #+#    #+#             */
/*   Updated: 2025/04/12 20:35:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl is ready to complain" << std::endl;
}

Harl::~Harl()
{
	std::cout << "destroing fat Harl" << std::endl;
}

void	Harl::complain(std::string check)
{
	void	(Harl::*level[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	Level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;

	for (int i = 0; check[i]; i++)
		check[i] = (char)std::toupper(check[i]);
	while (i < 5)
	{
		if (i < 4 && check == Level[i])
			break;
		if (i == 4)
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		i++;
	}
	while (i < 4)
	{
		std::cout << "[" << Level[i] << "]" << std::endl;
		(this->*level[i++])();
		std::cout << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}