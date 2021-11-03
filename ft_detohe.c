/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detohe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:09:38 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 11:08:16 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_detohe(unsigned long int n, int mayus)
{
	int		co;
	int		len;
	int		i;
	char	*string;

	co = 0;
	len = ft_hexalen(n);
	i = len - 1;
	string = malloc((len + 1) * sizeof(char));
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
