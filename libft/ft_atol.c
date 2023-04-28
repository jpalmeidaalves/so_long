/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:18:00 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/09 17:47:11 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	long	minus;

	i = 0;
	result = 0;
	minus = 1;
	while ((*(nptr + i) >= '\t' && (*(nptr + i) <= '\r')) || (*(nptr
				+ i) == ' '))
		i++;
	if (*(nptr + i) == '-' || *(nptr + i) == '+')
	{
		if (*(nptr + i) == '-')
			minus *= -1;
		i++;
	}
	while (*(nptr + i) >= '0' && *(nptr + i) <= '9')
	{
		result = (result * 10) + (*(nptr + i) - 48);
		i++;
	}
	return (minus * result);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
        printf("myatoi = %ld\n", ft_atol("454567432233556"));
        printf("atoi = %ld\n", atol("454567432233556"));
        printf("myatoi = %ld\n", ft_atol("      -2147483647"));
        printf("atoi = %ld\n", atol("    -2147483647"));
        printf("myatoi = %ld\n", ft_atol("      -2147483649"));
        printf("atoi = %ld\n", atol("    -2147483649"));



        return (0);
}*/
