/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:50:30 by fre007            #+#    #+#             */
/*   Updated: 2025/05/02 15:50:31 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Func.hpp"

std::tr1::mt19937 eng;

InitRandCaller initRandCaller;

void init_rand( void )
{
	unsigned long seed = time(NULL);
	eng.seed(seed);
}

Base *generate( void )
{
	std::tr1::uniform_int<int> dist(0, 2);
	int i = dist(eng);
	switch (i)
	{
	case 0:
		return new A();
		break;
	
	case 1:
		return new B();
		break;

	case 2:
		return new C();
		break;

	default:
		return NULL;
		break;
	}
}

void identify( Base *p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify( Base &p )
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}