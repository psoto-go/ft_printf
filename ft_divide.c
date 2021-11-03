/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:03:40 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 16:09:51 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_divide(unsigned long int n, int mayus, char *string, int len)
{
	int	co;
	int	i;

	co = 0;
	i = len - 1;
	while (n != 0)
	{
		co = n % 16;
		if (co < 10)
			co += 48;
		else if (co >= 10 && mayus == 0)
			co += 87;
		else if (co >= 10 && mayus == 1)
			co += 55;
		string[i--] = co;
		n /= 16;
	}
	string[len] = '\0';
	return (string);
}
