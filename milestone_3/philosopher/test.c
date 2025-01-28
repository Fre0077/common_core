/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:55 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/27 13:47:54 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*table_manage(void *temp)
{
	t_table	*table;
	int		i;

	table = (t_table *)temp;
	i = table->n_filo;

	while (1)
	{
		if (table->n_eat[i] == table->many_eat)
			return (printf("filosofo %d, è sazio\n", i), NULL);
		// printf("filosofo %d, cerca le forchette\n", i);
		// Asimmetria nella sequenza di acquisizione
		if (i % 2 == 0)
		{
			pthread_mutex_lock(&table->mutex[i]);
			pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
		}
		else
		{
			pthread_mutex_lock(&table->mutex[(i + 1) % table->many_filo]);
			pthread_mutex_lock(&table->mutex[i]);
		}
		// Mangia
		// printf("filosofo %d, mangia\n", i);
		usleep(table->eat_time * 1000); // Simula il tempo per mangiare
		table->n_eat[i] += 1;
		// Rilascia entrambe le forchette
		pthread_mutex_unlock(&table->mutex[i]);
		pthread_mutex_unlock(&table->mutex[(i + 1) % table->many_filo]);
		// Dorme
		// printf("filosofo %d, va a dormire\n\n", i);
		usleep(table->sleep_time * 1000); // Simula il tempo per dormire
	}
	return (NULL);
}

void	init_table(t_table *table, char **av, int ac)
{
	int	i;

	table->many_filo = ft_atoi(av[1]);
	table->mutex = malloc(sizeof(pthread_mutex_t) * table->many_filo);
	table->thread = malloc(sizeof(pthread_t) * table->many_filo);
	table->n_eat = malloc(sizeof(int) * table->many_filo);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	i = -1;
	while (++i < table->many_filo)
	{
		pthread_mutex_init(&table->mutex[i], NULL);
		table->n_eat[i] = 0;
	}
	if (ac == 6)
		table->many_eat = ft_atoi(av[5]);
}

int	main(int ac, char **av)
{
	int		i;
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (printf("E: too few arg...."), 0);
	table = malloc(sizeof(t_table));
	init_table(table, av, ac);
	i = -1;
	while (++i < table->many_filo)
	{
		table->n_filo = i;
		pthread_create(&table->thread[i], NULL, table_manage, (void *)table);
		usleep(20);
	}
	i = -1;
	while (++i < table->many_filo)
		pthread_join(table->thread[i], NULL);
	i = -1;
	while (++i < table->many_filo)
		pthread_mutex_destroy(&table->mutex[i]);
	return (0);
}
