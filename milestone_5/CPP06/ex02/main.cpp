/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:11:31 by francesco         #+#    #+#             */
/*   Updated: 2025/05/02 16:04:10 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Func.hpp"

int main ( void )
{
	Base *base = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	Base *base4 = NULL;
	Base &ref = *base;
	std::cout << "ref " << std::endl;
	identify(ref);
	std::cout << "pointer " << std::endl;
	identify(base);
	identify(*base);
	identify(base2);
	identify(*base2);
	identify(base3);
	identify(*base3);
	identify(base4);
	delete base;
	delete base2;
	delete base3;
	return 0;
}