/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:36:12 by fde-sant          #+#    #+#             */
/*   Updated: 2025/04/17 09:13:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("pasquale");
	AMateria* tmp2 = new Cure();
	src->learnMateria(tmp2);
	me->equip(tmp2);
	ICharacter* you = new Character("leonardo");
	AMateria* tmp = new Ice();
	src->learnMateria(tmp);
	you->equip(tmp);
	me->use(0, *you);
	you->use(0, *me);
	AMateria* tmp3 = src->createMateria("cure");
	AMateria* tmp4 = src->createMateria("cure");
	AMateria* tmp5 = src->createMateria("cure");
	AMateria* tmp6 = src->createMateria("ice");
	you->equip(tmp3);
	you->equip(tmp4);
	you->equip(tmp5);
	you->use(2, *me);
	you->use(1, *me);
	you->use(0, *me);
	you->equip(tmp6);
	you->use(0, *me);
	delete you;
	delete me;
	delete tmp;
	delete tmp2;
	delete tmp3;
	delete tmp4;
	delete tmp5;
	delete tmp6;
	delete src;
	return 0;
}