/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigputnbr_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:10:20 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/02 21:14:10 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_unsigputnbr_fd(unsigned int n, int fd, int *res)
{
	if (n >= 10)
		{
			ft_unsigputnbr_fd(n / 10, fd, res);
			ft_unsigputnbr_fd(n % 10, fd, res);
		}
	else
		{
			ft_putchar_fd(n + '0', fd, res);
		}
}
