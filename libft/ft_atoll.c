/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:23:32 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/09 17:47:23 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long long	ft_atoll(const char *nptr)
{
	int			i;
	long long	result;
	long long	minus;

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
        printf("myatoll = %lld\n", ft_atoll("9223372036854775807"));
        printf("atoll = %lld\n", atoll("9223372036854775807"));
        printf("myatoll = %lld\n", ft_atoll("      -2147483647"));
        printf("atoll = %lld\n", atoll("    -2147483647"));
        printf("myatoll = %lld\n", ft_atoll("      -2147483649"));
        printf("atol = %lld\n", atoll("    -2147483649"));
	printf("long long size: %ld\n", sizeof(long long));
	printf("long size: %ld\n", sizeof(long));
	printf("int size: %ld\n", sizeof(int));
	


        return (0);
}*/
