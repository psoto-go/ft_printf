/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:39:25 by psoto-go          #+#    #+#             */
/*   Updated: 2021/10/29 20:18:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n > -2147483648 || n <= 2147483647)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
		else
		{
			ft_putchar_fd(n + '0', fd);
		}
	}
}

void	ft_unputnbr_fd(int n, int fd)
{
	if (n > -2147483648 || n <= 2147483647)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(n, fd);
		}
		else
		{
			ft_putchar_fd(n + '0', fd);
		}
	}
}


void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	size_t			count;

	temp1 = (unsigned char *)str1;
	temp2 = (unsigned char *)str2;
	count = 0;
	if (str1 == NULL && str2 == NULL)
		return (NULL);
	while (count < n)
	{	
		temp1[count] = temp2[count];
		count++;
	}
	return (str1);
}


char	*ft_strdup(const char *src)
{
	char			*aux;
	size_t			len;

	len = ft_strlen(src) + 1;
	aux = (char *)malloc(len * sizeof(char));
	if (aux == NULL)
		return (NULL);
	ft_memcpy(aux, src, len);
	return (aux);
}


int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (0);
}

static int ft_print(char *c)
{
	char 	*aux;
	int		i;

	aux = ft_strdup(c);
	i = 0;
	while(aux[i] != '\0')
	{
		write(1, &aux[i], 1);
		i++;
	}
	return(0);
}

int ft_check(const char arg1, const char arg2, va_list args)
{
	int res;

	res = 0;
	if (arg1 == '%' && arg2 == 'c')
		ft_putchar_fd(va_arg(args, int), res);
	else if (arg1 == '%' && arg2 == 's')
		res = ft_print(va_arg(args, char *));
	else if (arg1 == '%' && arg2 == 'p')
	{
		ft_putnbr_fd(va_arg(args, unsigned long), res);
		// printf("%p", va_arg(args, char));
		// write(tmp[0], va_arg(args, char), 1);
	}
	else if (arg1 == '%' && arg2 == 'd')
		ft_putnbr_fd(va_arg(args, int), res);
	else if (arg1 == '%' && arg2 == 'i')
		ft_putnbr_fd(va_arg(args, int), res);
	else if (arg1 == '%' && arg2 == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), res);
	else if (arg1 == '%' && arg2 == '%')
		ft_putchar_fd('%', res);
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
		if(var[i] == '%')
		{
			res += ft_check
		(var[i], var[i + 1], args);
			i++;
		}else
		{
			write(1, &var[i], 1);
		}
		i++;
		
	}
	va_end(args);
	return (res);
}

int	main(){
	void *a;
	a = "aa";
	printf("%u\n", -3232);
	ft_printf("%u\n", -3232);
	printf("%s %d%%\n", "hello", 0);
	// system("leaks ft_printf.c");
	getchar();
	return(0);
}