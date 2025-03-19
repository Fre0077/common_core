/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:58:28 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/19 10:24:16 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer_bonus.h"

void	multi_post(sem_t *sem, int i)
{
	while (--i >= 0)
		sem_post(sem);
}

void	msleep(long long wait_time, t_table *table)
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

long long	actual_time(t_table *table)
{
	struct timeval	tv;
	long long		time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = time - table->start;
	return (time);
}

void	safe_print(char *str, t_table *table, int i)
{
	sem_wait(table->print);
	printf(str, actual_time(table), i + 1);
	sem_post(table->print);
}
