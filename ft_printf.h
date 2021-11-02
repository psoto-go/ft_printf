/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:43:33 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/02 19:38:18 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_detohe(int n, int mayus);

int		ft_hexalen(int n);

void	*ft_memcpy(void *str1, const void *str2, size_t n);

int 	ft_printf(const char *var, ...);

int		ft_putchar_fd(char c, int fd, int *res);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd, int *res);

void	ft_putstr_fd(char *s, int fd);

char	*ft_strdup(const char *src);

size_t	ft_strlen(const char *s);

int 	ft_write(char *c, int *res, int flag);

void	ft_unsigputnbr_fd(unsigned int n, int fd, int *res);


#endif
