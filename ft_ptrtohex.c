/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:39:06 by psoto-go          #+#    #+#             */
/*   Updated: 2021/11/03 16:36:22 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptrtohex(void *p)
{
	char	*aux;
	char	*ptr;
	int		len;

	ptr = ft_detohe((unsigned long int) p, 0);
	aux = malloc(sizeof(char) * (ft_strlen(ptr) + 3));
	if (!aux)
		return (0);
	len = ft_strlen(ptr);
	ft_strlcpy(aux, "0x", 3);
	ft_strlcat(aux, ptr, len + 3);
	free(ptr);
	return (aux);
}
