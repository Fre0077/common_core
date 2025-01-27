/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:58:37 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/27 11:11:45 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_table
{
	pthread_mutex_t	*mutex; //i mutex(forchetta)
	int				*used_mutex; //array che indica i mutex occupati
	pthread_t		*thread; //il thead(filosofo)
	int				*n_eat; //numero di volte che ha mangiato
	int				n_filo; //numero del filosofo in funzione
}	t_table;

#endif