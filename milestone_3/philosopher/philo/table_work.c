/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:03:20 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/19 10:19:41 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofer.h"

void	init_mutex(t_table *table)
{
	int	i;

	i = -1;
	table->mutex = malloc(sizeof(pthread_mutex_t) * table->many_filo);
	while (++i < table->many_filo)
		pthread_mutex_init(&table->mutex[i], NULL);
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->death_cond_mutex, NULL);
	pthread_mutex_init(&table->death_print_mutex, NULL);
	pthread_mutex_init(&table->n_filo_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
}

void	init_table(t_table *table, char **av, int ac)
{
	int				i;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	table->many_eat = 0;
	table->death = 0;
	table->n_filo = 0;
	table->start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	table->many_filo = ft_atoi(av[1]);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	table->thread = malloc(sizeof(pthread_t) * table->many_filo);
	table->n_eat = malloc(sizeof(int) * table->many_filo);
	table->last_eat = malloc(sizeof(long long) * table->many_filo);
	i = -1;
	while (++i < table->many_filo)
	{
		table->last_eat[i] = 0;
		table->n_eat[i] = 0;
	}
	if (ac == 6)
		table->many_eat = ft_atoi(av[5]);
	init_mutex(table);
}

void	free_all(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->many_filo)
		pthread_mutex_destroy(&table->mutex[i]);
	pthread_mutex_destroy(&table->death_mutex);
	pthread_mutex_destroy(&table->death_cond_mutex);
	pthread_mutex_destroy(&table->death_print_mutex);
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->n_filo_mutex);
	free(table->mutex);
	free(table->thread);
	free(table->n_eat);
	free(table->last_eat);
	free(table);
}
