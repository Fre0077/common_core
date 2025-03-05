/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:51:54 by fre007            #+#    #+#             */
/*   Updated: 2025/01/29 10:08:11 by fre007           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//include:
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

//definizione delle struct:

//printf
int	ft_printf(const char *n, ...);
int	ft_putnbr_fd(long n, int fd);
int	ft_putnbr_un(unsigned int n);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putbase_long(void *n, char *base);
int	ft_putbase(unsigned long n, char *base);

//get_next_line
char	*get_next_line(int fd);
int		check_buffer(char *buffer, int check_case);
int		buffer_size(char *buffer, char *join);
char	*return_buffer(char **buffer);
void	next_buffer(char **buffer, int i);
void	join_buffer(char *buffer, char *temp, char *join);

//definizioni delle funzioni:
char	*ft_calloc(long size);
long	*ft_callocn(long size);

char	*ft_itoa(long num);
long	ft_atoi(char *str);

int	find_cinstr(char c, char *str);
int	find_ninarr(long n, long *arr, int size);

int	cmpstr_all(char *str1, char *str2);
int cmpstr_till_end(char *str1, char *str2);
int cmpstr_till_n(char *str1, char *str2, int n);
int cmpstr_n_to_n(char *str1, char *str2, int start, int end); //da fare

int ft_strlen(char *str);

int isletter(char c);
int isnumber(char c);

#endif