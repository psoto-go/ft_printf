/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:09:15 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 15:09:09 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexalen(unsigned long int n)
{
	unsigned long int	co;
	int					count;

	co = 0;
	count = 1;
	while (n >= 16)
	{
		co = n / 16;
		n = co;
		count++;
	}
	return (count);
}
