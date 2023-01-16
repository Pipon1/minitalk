/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:30:55 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/12 16:33:17 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t	i;
	size_t	size;
	size_t	start;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start != i)
			size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	start;
	size_t	size;

	size = ft_countwords(s, c);
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start != i)
			res[size++] = ft_substr(s, start, i - start);
	}
	res[size] = NULL;
	return (res);
}
