/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-sant <fde-sant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:57:20 by fde-sant          #+#    #+#             */
/*   Updated: 2025/01/09 10:39:33 by fde-sant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../ft_printf.h"

int		ft_countc_matrix(char **matrix, char c, int height);
int		ft_countc(char *str, char c);
int		ft_findc(char *str, char c);
int		ft_distance(int a, int middle, int b);
int		ft_diff(int a, int b);
int		ft_strlen(char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_un(unsigned int n);

char	*ft_calloc(int len);
char	*ft_itoa(int n);
char	*ft_add(char *to, char *add);

void	ft_putendl_fd(char *s, int fd);
void	ft_freematrix(char **matrix, int height);
void	ft_print_matrix(char **matrix);

#endif