/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_pointer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 12:02:08 by psoto-go          #+#    #+#             */
/*   Updated: 2022/01/22 13:47:06 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_pointer(int n, int fd, int *res)
{
	if (n > -2147483648 || n <= 2147483647)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd_pointer('-', fd, res);
			ft_putchar_fd_pointer('2', fd, res);
			ft_putnbr_fd_pointer(147483648, fd, res);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd_pointer(n / 10, fd, res);
			ft_putnbr_fd_pointer(n % 10, fd, res);
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar_fd_pointer('-', fd, res);
			ft_putnbr_fd_pointer(n, fd, res);
		}
		else
		{
			ft_putchar_fd_pointer(n + '0', fd, res);
		}
	}
}
