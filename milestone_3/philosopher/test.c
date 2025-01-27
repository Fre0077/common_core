/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:55 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/27 11:27:56 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*table_manage(void *temp)
// {
// 	t_table	*table;
// 	int		i;

// 	table = (t_table *)temp;
// 	i = table->n_filo;
// 	while (1)
// 	{
// 		if (table->n_eat[i] == 4)
// 		{
// 			printf("-------------------filosofo %d, e' sazzio\n\n", i);
// 			return (NULL);
// 		}
// 		pthread_mutex_lock(&table->glob);
// 		printf("filosofo %d, cerca le forchette\n", i);
// 		printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
// 		if (table->used_mutex[i] == 0 && table->used_mutex[(i + 1) % 4] == 0)
// 		{
// 			table->used_mutex[i] = 1;
// 			table->used_mutex[(i + 1) % 4] = 1;
// 			pthread_mutex_unlock(&table->glob);
// 			pthread_mutex_lock(&table->mutex[i]);
// 			pthread_mutex_lock(&table->mutex[(i + 1) % 4]);
// 			printf("filosofo %d, prende forchetta %d e %d\n", i, i, (i + 1) % 4);
// 			printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
// 			usleep(100); // non funziona con numeri bassi <200, ad una cerca c'e un processo che si sovrappone
// 			table->used_mutex[i] = 0;
// 			table->used_mutex[(i + 1) % 4] = 0;
// 			pthread_mutex_unlock(&table->mutex[i]);
// 			pthread_mutex_unlock(&table->mutex[(i + 1) % 4]);
// 			table->n_eat[i] += 1;
// 			printf("filosofo %d, posa forchetta %d e %d e va a dormire\n", i, i, (i + 1) % 4);
// 			printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
// 			printf("filosofo %d, va a dormire\n\n", i);
// 			usleep(1000000);
// 			printf("filosofo %d, si sveglia\n", i);
// 		}
// 		pthread_mutex_unlock(&table->glob);
// 		printf("filosofo %d, inizia a pensare\n\n", i);
// 		while (table->used_mutex[i] != 0 || table->used_mutex[(i + 1) % 4] != 0)
// 			usleep(1);
// 		printf("filosofo %d, smette di pensare\n", i);
// 	}
// 	return(NULL);
// }

void	*table_manage(void *temp)
{
	t_table	*table;
	int		i;

	table = (t_table *)temp;
	i = table->n_filo;
	while (1)
	{
		if (table->n_eat[i] == 4)
			return (printf("-------------------filosofo %d, e' sazzio\n\n", i), NULL);
		printf("filosofo %d, cerca le forchette\n", i);
		// printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
		//prende prima forchetta
		pthread_mutex_lock(&table->mutex[i]);
		pthread_mutex_lock(&table->mutex[(i + 1) % 4]);
		table->used_mutex[i] = 1;
		table->used_mutex[(i + 1) % 4] = 1;
		// printf("filosofo %d, prende forchetta %d\n", i, i);
		//prende seconda forchetta
		printf("filosofo %d, mangia\n", i);
		printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
		//mangia
		usleep(100); // non funziona con numeri bassi <200, ad una cerca c'e un processo che si sovrappone
		table->n_eat[i] += 1;
		//posa prima forchetta
		pthread_mutex_unlock(&table->mutex[i]);
		pthread_mutex_unlock(&table->mutex[(i + 1) % 4]);
		table->used_mutex[i] = 0;
		table->used_mutex[(i + 1) % 4] = 0;
		// printf("filosofo %d, posa forchetta %d\n", i, i);
		//posa seconda forchetta
		// printf("filosofo %d, posa forchetta %d\n", i, (i + 1) % 4);
		// printf("[%d]{%d}fork0: %d, fork1: %d, fork2: %d, fork3: %d\n", i, table->n_eat[i], table->used_mutex[0], table->used_mutex[1], table->used_mutex[2], table->used_mutex[3]);
		//dormono
		printf("filosofo %d, va a dormire\n\n", i);
		usleep(1000000);
		printf("filosofo %d, si sveglia\n", i);
	}
	return(NULL);
}

void	init_table(t_table *table)
{
	int	i;

	table->mutex = malloc(sizeof(pthread_mutex_t) * 4);
	table->used_mutex = malloc(sizeof(int) * 4);
	table->thread = malloc(sizeof(pthread_t) * 4);
	table->n_eat = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < 4)
	{
		pthread_mutex_init(&table->mutex[i], NULL);
		table->used_mutex[i] = 0;
		table->n_eat[i] = 0;
	}
}

int main()
{
	int		i;
	t_table	*table;
	
	table = malloc(sizeof(t_table *));
	init_table(table);
	i = -1;
	while (++i < 4)
	{
		table->n_filo = i;
		pthread_create(&table->thread[i], NULL, table_manage, (void *)table);
		usleep(10);
	}
	i = -1;
	while (++i < 4)
		pthread_join(table->thread[i], NULL);
	i = -1;
	while (++i < 4)
		pthread_mutex_destroy(&table->mutex[i]);
	return 0;
}
