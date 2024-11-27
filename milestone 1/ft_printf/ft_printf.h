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

#ifndef PRINTF_H
# define PRINTF_H
# include "libft/libft.h"

int	ft_printf(const char *n, ...);
int	ft_putbase(unsigned long n, char *base);
int	ft_putbase_long(unsigned long n);

#endif