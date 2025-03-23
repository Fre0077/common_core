/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:58:28 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/21 12:21:25 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

//riproduzione del usleep con modifiche
void	msleep(long long wait_time)
{
	struct timeval	tv;
	long long		time;
	long long		limit;

	gettimeofday(&tv, NULL);
	limit = (tv.tv_sec * 1000000) + (tv.tv_usec) + wait_time;
	time = (tv.tv_sec * 1000000) + (tv.tv_usec);
	while (time < limit)
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000000) + (tv.tv_usec);
	}
}

//ritorna il tempo passato dall'inizio del programma
long long	actual_time(t_table *table)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = time - table->start;
	return (time);
}

//print esclusivo per quando muore un filosofo
void	death_print(char *str, t_table *table, int i)
{
	sem_wait(table->check);
	sem_wait(table->print);
	if (table->death_check)
	{
		printf(str, actual_time(table), i + 1);
	}
	sem_post(table->print);
	sem_post(table->check);
}

//print sicuro per la stampa
void	safe_print(char *str, t_table *table, int i)
{
	sem_wait(table->death_print);
	sem_post(table->death_print);
	sem_wait(table->check);
	sem_wait(table->print);
	if (table->death_check)
		printf(str, actual_time(table), i + 1);
	sem_post(table->print);
	sem_post(table->check);
}
