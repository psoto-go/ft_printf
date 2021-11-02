/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:39:25 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/02 21:19:56 by psoto-go         ###   ########.fr       */
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

void		ft_putnbr_fd(int n, int fd, int *res)
{
	if (n > -2147483648 || n <= 2147483647)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd, res);
			ft_putchar_fd('2', fd, res);
			ft_putnbr_fd(147483648, fd, res);
		}
		else if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd, res);
			ft_putnbr_fd(n % 10, fd, res);
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar_fd('-', fd, res);
			ft_putnbr_fd(n, fd, res);
		}
		else
		{
			ft_putchar_fd(n + '0', fd, res);
		}
	}
}

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


void	ft_putchar_fd(char c, int fd, int *res)
{
	*res += 1;
	write(fd, &c, 1);
}

void	 ft_write(char *c, int *res, int flag)
{
	char 	*aux;
	int		i;

	aux = ft_strdup(c);
	i = 0;
	while(aux[i] != '\0')
	{
		write(1, &aux[i], 1);
		i++;
		*res += 1;
	}
	free(aux);
	if (flag == 1)
		free(c);
	}

int	ft_hexalen(int n)
{
	int co;
	int count;
	
	co = 0;
	count = 1;
	while (n >= 16){
		co = n / 16;
		n = co;
		count++;
	}
	return (count);
}


char	*ft_detohe(int n, int mayus)
{
	int co;
	int len;
	int i;
	char *string;
	
	co = 0;
	len = ft_hexalen(n);
	i = len - 1;
	string = malloc((len + 1) * sizeof(char));
	if (!string)
		return (0);
	if (n == 0)
		string[len - 1] = '0';
	while (n != 0){
		co = n % 16;
		if(co < 10)
			co += 48;
		else if(co >= 10 && mayus == 0)
			co += 87;
		else if(co >= 10 && mayus == 1)
			co += 55;
		string[i--] = co;
		n /= 16;
	}
	string[len] = '\0';
	return (string);
}

int ft_check(const char arg1, const char arg2, va_list args)
{
	int res;

	res = 0;
	if (arg1 == '%' && arg2 == 'c')
		ft_putchar_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 's')
		ft_write(va_arg(args, char *), &res, 0);
	// else if (arg1 == '%' && arg2 == 'p')
	// {
	// 	ft_putnbr_fd(va_arg(args, unsigned long), res);
	// 	// printf("%p", va_arg(args, char));
	// 	// write(tmp[0], va_arg(args, char), 1);
	// }
	else if (arg1 == '%' && arg2 == 'd')
		ft_putnbr_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 'i')
		ft_putnbr_fd(va_arg(args, int), 1, &res);
	else if (arg1 == '%' && arg2 == 'u')
		ft_unsigputnbr_fd(va_arg(args, unsigned int), 1, &res);
	else if (arg1 == '%' && arg2 == 'x')
		ft_write(ft_detohe(va_arg(args, int), 0), &res, 1);
	else if (arg1 == '%' && arg2 == 'X')
		ft_write(ft_detohe(va_arg(args, int), 1), &res, 1);
	else if (arg1 == '%' && arg2 == '%')
		ft_putchar_fd('%', 1, &res);
	return (res);
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
			res += ft_check(var[i], var[i + 1], args);
			i++;
		}else
		{
			write(1, &var[i], 1);
			res++;
		}
		i++;
	}
	va_end(args);
	return (res);
}

int	main(){
	void *a;
	a = "aa";
	// printf("%p\n", a);
	// ft_printf("%s hola\n", "3232");
	// printf("%s %d%% hola\n", "hello", 0);
	// // system("leaks ft_printf.c");
	// printf("%d\n", -2147483647);
	// ft_printf("%d\n\n", -2147483647);
	printf(" %x \n", 32);
	ft_printf(" %x ", 32);
	return(0);
}
