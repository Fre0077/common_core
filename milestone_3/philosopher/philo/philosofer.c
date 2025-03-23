/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:55 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/23 11:28:47 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

//controlla che non tutti i filosofi siano sazzi
int	full_check(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->many_filo)
	{
		pthread_mutex_lock(&table->death_cond_mutex);
		if (table->many_eat != 0 && table->n_eat[i] < table->many_eat)
		{
			pthread_mutex_unlock(&table->death_cond_mutex);
			break ;
		}
		pthread_mutex_unlock(&table->death_cond_mutex);
	}
	if (i == table->many_filo)
		return (0);
	else
		return (1);
}

//controlla che tutti i filosofi siano vivi e che non siano sazzi
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
		if (full_check(table))
			return (NULL);
		while (++i < table->many_filo)
		{
			pthread_mutex_lock(&table->death_cond_mutex);
			if (time - table->last_eat[i] > table->die_time)
			{
				pthread_mutex_unlock(&table->death_cond_mutex);
				death_print("%lld %d died\n", table, i);
				return (NULL);
			}
			pthread_mutex_unlock(&table->death_cond_mutex);
		}
	}
}

//mangiano e dormono
void	eat(t_table *table, int i)
{
	safe_print("%lld %d is thinking\n", table, i);
	if (i == table->many_filo - 1)
	{
		pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
		safe_print("%lld %d has taken a fork\n", table, i);
		pthread_mutex_lock(&table->mutex[i]);
	}
	else
	{
		msleep(100, table);
		pthread_mutex_lock(&table->mutex[i]);
		safe_print("%lld %d has taken a fork\n", table, i);
		pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
	}
	safe_print("%lld %d has taken a fork\n", table, i);
	pthread_mutex_lock(&table->death_cond_mutex);
	table->last_eat[i] = actual_time(table);
	table->n_eat[i] += 1;
	pthread_mutex_unlock(&table->death_cond_mutex);
	safe_print("%lld %d is eating\n", table, i);
	msleep(table->eat_time * 1000, table);
	pthread_mutex_unlock(&table->mutex[i]);
	pthread_mutex_unlock(&table->mutex[(i + 1) % table->many_filo]);
	safe_print("%lld %d is sleeping\n", table, i);
	msleep((table->sleep_time * 1000) + 100, table);
}

//gestione delle dinamiche del tavolo per fa mangiare i philosofi
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
			return (NULL);
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
		msleep(500, table);
	}
	pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
	i = -1;
	while (++i < table->many_filo)
		pthread_join(table->thread[i], NULL);
	pthread_join(table->gurdian, NULL);
	return (free_all(table), 0);
}
