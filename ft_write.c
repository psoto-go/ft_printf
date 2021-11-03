/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:08:53 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 17:21:24 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(char *c, int *res, int flag)
{
	char	*aux;
	int		i;

	if (c == NULL)
		aux = ft_strdup("(null)");
	else
		aux = ft_strdup(c);
	if (!aux)
		return ;
	i = 0;
	while (aux[i] != '\0')
	{
		write(1, &aux[i], 1);
		i++;
		*res += 1;
	}
	free(aux);
	if (flag == 1)
		free(c);
}
