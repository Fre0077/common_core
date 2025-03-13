/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 10:58:28 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/13 12:33:04 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

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
		pthread_mutex_lock(&table->death_mutex);
		if (table->death)
		{
			pthread_mutex_unlock(&table->death_mutex);
			return ;
		}
		pthread_mutex_unlock(&table->death_mutex);
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000000) + (tv.tv_usec);
	}
}

long long	actual_time(t_table *table)
{
	struct timeval	tv;
	long long		time;

	pthread_mutex_lock(&table->time_mutex);
	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	time = time - table->start;
	pthread_mutex_unlock(&table->time_mutex);
	return (time);
}

void	death_print(char *str, t_table *table, int i)
{
	pthread_mutex_lock(&table->death_print_mutex);
	printf(str, actual_time(table), i + 1);
	pthread_mutex_unlock(&table->death_print_mutex);
}

void	safe_print(char *str, t_table *table, int i)
{
	int	death;

	pthread_mutex_lock(&table->death_mutex);
	death = table->death;
	pthread_mutex_unlock(&table->death_mutex);
	pthread_mutex_lock(&table->print_mutex);
	pthread_mutex_lock(&table->death_print_mutex);
	if (!death)
		printf(str, actual_time(table), i + 1);
	pthread_mutex_unlock(&table->death_print_mutex);
	pthread_mutex_unlock(&table->print_mutex);
}
