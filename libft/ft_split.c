/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <joaoalme@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:34:14 by joaoalme          #+#    #+#             */
/*   Updated: 2022/11/14 19:23:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	words;
	int	index;
	int	is_new;

	is_new = 1;
	index = 0;
	words = 0;
	while (s[index])
	{
		if (s[index] == c)
			is_new = 1;
		if (s[index] != c && is_new)
		{
			words++;
			is_new = 0;
		}
		index++;
	}
	return (words);
}

char	*ft_get_word(char *s, char c)
{
	char	*dest;
	int		end;
	int		i;

	i = 0;
	end = 0;
	while (s[end] != c && s[end] != '\0')
		end++;
	i = end;
	dest = malloc(sizeof(char) * end + 1);
	if (!dest)
		return (NULL);
	dest[end] = '\0';
	while (i > 0)
		dest[--end] = s[--i];
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		word_count;
	int		word_len;

	if (!s)
		return (NULL);
	word_len = ft_count_words(s, c);
	word_count = 0;
	array = malloc(sizeof(char *) * (word_len + 1));
	if (!array)
		return (NULL);
	while (word_count < word_len)
	{
		while (*s == c)
			s++;
		array[word_count] = ft_get_word((char *)s, c);
		word_count++;
		while (*s != c && *s != '\0')
			s++;
	}
	array[word_count] = 0;
	return (array);
}

/*
#include <stdio.h>

void	ft_print_array(char **array)
{
	int i;

	if (array == NULL)
		printf("Array is NULL\n");
	else
	{
		for(i = 0; array[i] != NULL; i++)
			printf("%d - %s\n", i, array[i]);
		printf("%d - NULL\n", i);
	}
}

int	main(void)
{
	char *str = "teste funcao todo atoa";
	char c = ' ';
	ft_print_array(ft_split(str, c));
}*/
