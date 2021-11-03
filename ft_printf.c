/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:39:25 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 16:19:08 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char arg1, const char arg2, va_list args)
{
	int	res;

	res = 0;
	if (arg1 == '%' && arg2 == 'c')
		ft_putchar_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 's')
		ft_write(va_arg(args, char *), &res, 0);
	else if (arg1 == '%' && arg2 == 'p')
		ft_write(ft_ptrtohex(va_arg(args, void *)), &res, 1);
	else if (arg1 == '%' && arg2 == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 'u')
		ft_unsigputnbr_fd(va_arg(args, unsigned int), 1, &res);
	else if (arg1 == '%' && arg2 == 'x')
		ft_write(ft_detohe(va_arg(args, unsigned int), 0), &res, 1);
	else if (arg1 == '%' && arg2 == 'X')
		ft_write(ft_detohe(va_arg(args, unsigned int), 1), &res, 1);
	else if (arg1 == '%' && arg2 == '%')
		ft_putchar_fd('%', 1, &res);
	return (res);
}

int	ft_printf(const char *var, ...)
{
	va_list	args;
	int		i;
	int		res;

	va_start(args, var);
	i = 0;
	res = 0;
	while (var[i] != '\0')
	{
		if (var[i] == '%')
		{
			res += ft_check(var[i], var[i + 1], args);
			i++;
		}
		else
		{
			write(1, &var[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}
