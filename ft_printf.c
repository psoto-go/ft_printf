/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:39:25 by psoto-go          #+#    #+#             */
/*   Updated: 2021/10/28 17:32:00 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return(0);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_putstr_fd(char *s)
{
	int		i;
	int		len;
	
	i = 0;
	if (!s)
		return(write(1, "(null)", 6));
	len = ft_strlen(s);
	while (i < len)
	{
		ft_putchar_fd(s[i],1);
		i++;
	}
	return (i);
}

int ft_comprueba(const char arg1, const char arg2, va_list args)
{
	int res;

	res = 0;
	if (arg1 == '%' && arg2 == 'c')
	{
		res = ft_putchar_fd(va_arg(args, int),1);
	}
	else if (arg1 == '%' && arg2 == 's')
	{
		res = ft_putstr_fd(va_arg(args, char));
		// printf("%s", va_arg(args, char));
		// write(tmp[0], va_arg(args, char), 1);
	}
	else if (arg1 == '%' && arg2 == 'p')
	{
		// printf("%p", va_arg(args, char));
		// write(tmp[0], va_arg(args, char), 1);
	}
	else if (arg1 == '%' && arg2 == 'd')
	{
		// printf("%d", va_arg(args, int));
		// ft_putnbr_fd(va_arg(args, long), &res);
	}
	else if (arg1 == '%' && arg2 == 'i')
	{
		// printf("%i", va_arg(args, char));
		// write(tmp[0], va_arg(args, char), 1);
	}
	return(res);
	
}

int ft_printf(const char *var, ...)
{
	va_list args;
	int		i;
	int		res;

	va_start( args, var );
	i = 0;
	res = 0;

	while (var[i] != '\0')
	{
		res += ft_comprueba(var[i], var[i + 1], args);
		i++;
	}
	va_end(args);
	return (res);
}

int	main(){
	printf("%s\n", "'aa'");
	ft_printf("%s", "aa");
}