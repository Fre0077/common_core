/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:55 by fde-sant          #+#    #+#             */
/*   Updated: 2025/03/05 09:32:14 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	msleep(long long wait_time)
{
	struct		timeval tv;
	long long	time;
	long long	limit;

	gettimeofday(&tv, NULL);
	limit = (tv.tv_sec * 1000000) + (tv.tv_usec) + wait_time;
	time = (tv.tv_sec * 1000000) + (tv.tv_usec);
	while(time < limit)
	{
		gettimeofday(&tv, NULL);
		time = (tv.tv_sec * 1000000) + (tv.tv_usec);
	}
}

long long	actual_time(t_table *table)
{
	struct		timeval tv;
	long long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time - table->start);
}

void safe_print(char *str, t_table *table, int i)
{
	pthread_mutex_lock(&table->print_mutex);
	if (!table->death)
		printf(str, actual_time(table), i + 1);
	pthread_mutex_unlock(&table->print_mutex);
}

void	*death_checker(void *temp)
{
	t_table			*table;
	long long		time;
	int				i;

	table = (t_table *)temp;
	while (1)
	{
		i = -1;
		msleep (1000);
		time = actual_time(table);
		pthread_mutex_lock(&table->death_mutex);
		while (++i < table->many_filo)
		{
			if (table->last_eat[i] != 0 && (table->n_eat[i] < table->many_eat || table->many_eat == 0)
				&& time - table->last_eat[i] > table->die_time)
			{
				safe_print("%lld filosofo %d, è morto\n", table, i);
				table->death = 1;
			}
		}
		pthread_mutex_unlock(&table->death_mutex);
		if (table->death)
			break ;
	}
	return (NULL);
}
	
void	eat(t_table *table, int	i)
{
	// Asimmetria nella sequenza di acquisizione
	safe_print("%lld filosofo %d, pensa\n", table, i);
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
	//write(1, "caio\n", 5);
	table->last_eat[i] = 0;
	safe_print("%lld filosofo %d, sta mangiando\n", table, i);
	if (!table->death)
		msleep(table->eat_time * 1000); // Simula il tempo per mangiare
	table->last_eat[i] = actual_time(table);
	// Rilascia entrambe le forchette
	pthread_mutex_unlock(&table->mutex[i]);
	pthread_mutex_unlock(&table->mutex[(i + 1) % table->many_filo]);
	safe_print("%lld filosofo %d, finisce di mangiare\n", table, i);
	table->n_eat[i] += 1;
}

void	*table_manage(void *temp)
{
	t_table	*table;
	int		i;

	table = (t_table *)temp;
	i = table->n_filo;
	while (1)
	{
		if (table->death)
			break ;
		if (table->many_eat && table->n_eat[i] == table->many_eat)
			return (printf("%lld filosofo %d, è sazio\n", actual_time(table), i), NULL);
		// Mangia
		eat(table, i);
		// Dorme
		safe_print("%lld filosofo %d, dorme\n", table, i);
		usleep(table->sleep_time * 1000); // Simula il tempo per dormire
		safe_print("%lld filosofo %d, si sveglia\n", table, i);
	}
	return (NULL);
}

void	init_table(t_table *table, char **av, int ac)
{
	int	i;
	struct		timeval tv;

	gettimeofday(&tv, NULL);
	table->start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	table->many_filo = ft_atoi(av[1]);
	table->mutex = malloc(sizeof(pthread_mutex_t) * table->many_filo);
	table->thread = malloc(sizeof(pthread_t) * table->many_filo);
	table->n_eat = malloc(sizeof(int) * table->many_filo);
	table->last_eat = malloc(sizeof(long long) * table->many_filo);
	table->die_time = ft_atoi(av[2]);
	table->eat_time = ft_atoi(av[3]);
	table->sleep_time = ft_atoi(av[4]);
	i = -1;
	while (++i < table->many_filo)
	{
		table->last_eat[i] = 0;
		pthread_mutex_init(&table->mutex[i], NULL);
		table->n_eat[i] = 0;
	}
	pthread_mutex_init(&table->death_mutex, NULL);
	pthread_mutex_init(&table->print_mutex, NULL);
	table->many_eat = 0;
	if (ac == 6)
		table->many_eat = ft_atoi(av[5]);
	table->death = 0;
}

int	main(int ac, char **av)
{
	int		i;
	t_table	*table;

	if (ac != 5 && ac != 6)
		return (printf("E: too few arg...."), 0);
	table = malloc(sizeof(t_table));
	init_table(table, av, ac);
	pthread_create(&table->gurdian, NULL, death_checker, (void *)table);
	i = -1;
	while (++i < table->many_filo)
	{
		table->n_filo = i;
		pthread_create(&table->thread[i], NULL, table_manage, (void *)table);
		msleep(50);
	}
	i = -1;
	while (++i < table->many_filo)
	{
		pthread_join(table->thread[i], NULL);
		printf("philo:%d\n", i);
	}
	pthread_join(table->gurdian, NULL);
	printf("gurdian\n");
	i = -1;
	while (++i < table->many_filo)
		pthread_mutex_destroy(&table->mutex[i]);
	return (0);
}
