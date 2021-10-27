/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:39:25 by psoto-go          #+#    #+#             */
/*   Updated: 2021/10/27 16:37:47 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_printf(const char *a, const char *c)
{
	char	*tmp;
	int		len;
	int 	i;

	len = strlen(c);
	tmp = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if(a == "%c")
	{
		write(tmp[0], &c[0], 1);
	}
	if(a == "%s")
	{
		while(i <= len)
		{
			write(tmp[i], &c[i], 1);
			i++;
		}
	}
	
	return (tmp);
}

int	main(){
	// printf("%c\n", "abcdefghijklmnñopqrstuvwxyz");
	ft_printf("%c", "abcdefghijklmnñopqrstuvwxyz");
	
}