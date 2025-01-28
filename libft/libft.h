/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fre007 <fre007@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:51:54 by fre007            #+#    #+#             */
/*   Updated: 2025/01/28 20:58:57 by fre007           ###   ########.fr       */
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

//definizioni delle funzioni:
char	*ft_calloc(long size);
long	*ft_callocn(long size);

char	*ft_itoa(long num);
long	ft_atoi(char *str);

int	find_cinstr(char c, char *str);
int	find_ninarr(long n, long *arr, int size);

int isletter(char c);
int isnumber(char c);

int	ft_printf(const char *n, ...);
int	ft_putnbr_fd(long n, int fd);
int	ft_putnbr_un(unsigned int n);
int	ft_putstr_fd(char *s, int fd);
int	ft_putchar_fd(char c, int fd);
int	ft_putbase_long(void *n, char *base);
int	ft_putbase(unsigned long n, char *base);

#endif