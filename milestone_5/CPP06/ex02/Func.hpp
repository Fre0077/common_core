/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Func.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:49:30 by fre007            #+#    #+#             */
/*   Updated: 2025/05/02 15:49:32 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNC_HPP
#define FUNC_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <tr1/random>

void init_rand( void );

class InitRandCaller {
public:
	InitRandCaller() {
		init_rand();
	}
};

Base *generate( void );
void identify( Base *p );
void identify( Base &p );

#endif