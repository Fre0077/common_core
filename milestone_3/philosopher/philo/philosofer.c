/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:55 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/18 17:51:46 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

void	*death_checker(void *temp)
{
	t_table			*table;
	long long		time;
	int				i;

	table = (t_table *)temp;
	while (1)
	{
		i = -1;
		msleep (1000, table);
		time = actual_time(table);
		while (++i < table->many_filo)
		{
			pthread_mutex_lock(&table->death_cond_mutex);
			if ((table->n_eat[i] < table->many_eat || table->many_eat == 0)
				&& time - table->last_eat[i] > table->die_time)
			{
				pthread_mutex_unlock(&table->death_cond_mutex);
				death_print("%lld %d died\n", table, i);
				return (NULL);
			}
			pthread_mutex_unlock(&table->death_cond_mutex);
		}
	}
}

void	eat(t_table *table, int i)
{
	safe_print("%lld %d is thinking\n", table, i);
	//msleep(500, table);
	if (i % 2 == 0)
	{
		pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
		pthread_mutex_lock(&table->mutex[i]);
	}
	else
	{
		pthread_mutex_lock(&table->mutex[i]);
		pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
	}
	pthread_mutex_lock(&table->death_cond_mutex);
	table->last_eat[i] = actual_time(table);
	table->n_eat[i] += 1;
	pthread_mutex_unlock(&table->death_cond_mutex);
	safe_print("%lld %d is eating\n", table, i);
	msleep(table->eat_time * 1000, table);
	pthread_mutex_unlock(&table->mutex[(i + 1) % table->many_filo]);
	pthread_mutex_unlock(&table->mutex[i]);
	safe_print("%lld %d is sleeping\n", table, i);
	msleep((table->sleep_time * 1000) + 100, table);
}

void	*table_manage(void *temp)
{
	t_table	*table;
	int		i;

	table = (t_table *)temp;
	pthread_mutex_lock(&table->n_filo_mutex);
	i = table->n_filo++;
	pthread_mutex_unlock(&table->n_filo_mutex);
	while (1)
	{
		pthread_mutex_lock(&table->death_mutex);
		if (table->death)
			return (pthread_mutex_unlock(&table->death_mutex), NULL);
		pthread_mutex_unlock(&table->death_mutex);
		pthread_mutex_lock(&table->death_cond_mutex);
		if (table->many_eat && table->n_eat[i] == table->many_eat)
		{
			pthread_mutex_unlock(&table->death_cond_mutex);
			return (safe_print("%lld filosofo %d, è sazio\n", table, i), NULL);
		}
		pthread_mutex_unlock(&table->death_cond_mutex);
		eat(table, i);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	int		i;
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (printf("E: too few arg...."), 0);
	table = malloc(sizeof(t_table));
	init_table(table, av, ac);
	if (table->many_filo < 0 || table->die_time < 0
		|| table->eat_time < 0 || table->sleep_time < 0)
		return (printf("wrong argoment\n"), 0);
	i = -1;
	while (table->many_filo > 1 && ++i < table->many_filo)
	{
		pthread_mutex_lock(&table->death_cond_mutex);
		table->last_eat[i] = actual_time(table);
		pthread_mutex_unlock(&table->death_cond_mutex);
		pthread_create(&table->thread[i], NULL, table_manage, (void *)table);
	}
	msleep(50, table);
	pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
	i = -1;
	while (++i < table->many_filo)
		pthread_join(table->thread[i], NULL);
	pthread_join(table->gurdian, NULL);
	return (free_all(table), 0);
}
