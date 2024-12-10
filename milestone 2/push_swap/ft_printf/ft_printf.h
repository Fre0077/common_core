/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarbona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:48:01 by ecarbona          #+#    #+#             */
/*   Updated: 2024/11/26 15:21:22 by ecarbona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);

int	ft_putnbr_un(unsigned int n);
int	ft_putbase(unsigned long n, char *base);
int	ft_putbase_long(unsigned long n, char *base);

int	ft_putchar(char c, int fd);
int	ft_putnbr(int n, int fd);
int	ft_putstr(char *s, int fd);

#endif