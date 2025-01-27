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
		if (table->n_eat[i] == 100)
			return (printf("-------------------filosofo %d, e' sazio\n\n", i), NULL);
		printf("filosofo %d, cerca le forchette\n", i);
		// Asimmetria nella sequenza di acquisizione
		if (i % 2 == 0)
		{
			pthread_mutex_lock(&table->mutex[i]);
			pthread_mutex_lock(&table->mutex[(i + 1) % 4]);
		}
		else
		{
			pthread_mutex_lock(&table->mutex[(i + 1) % 4]);
			pthread_mutex_lock(&table->mutex[i]);
		}
		// Mangia
		printf("filosofo %d, mangia\n", i);
		usleep(100); // Simula il tempo per mangiare
		table->n_eat[i] += 1;
		// Rilascia entrambe le forchette
		pthread_mutex_unlock(&table->mutex[i]);
		pthread_mutex_unlock(&table->mutex[(i + 1) % 4]);
		// Dorme
		printf("filosofo %d, va a dormire\n\n", i);
		usleep(500000); // Simula il tempo per dormire
	}
	return (NULL);
}

void	init_table(t_table *table)
{
	int	i;

	table->mutex = malloc(sizeof(pthread_mutex_t) * 4);
	table->thread = malloc(sizeof(pthread_t) * 4);
	table->n_eat = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
	{
		pthread_mutex_init(&table->mutex[i], NULL);
		table->n_eat[i] = 0;
	}
}

int	main()
{
	int		i;
	t_table	*table;

	table = malloc(sizeof(t_table));
	init_table(table);
	i = -1;
	while (++i < 4)
	{
		table->n_filo = i;
		pthread_create(&table->thread[i], NULL, table_manage, (void *)table);
		usleep(10); // Leggero ritardo per evitare problemi di partenza simultanea
	}
	i = -1;
	while (++i < 4)
		pthread_join(table->thread[i], NULL);
	i = -1;
	while (++i < 4)
		pthread_mutex_destroy(&table->mutex[i]);
	return (0);
}
