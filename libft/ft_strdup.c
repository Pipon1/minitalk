/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:14:27 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/11 11:38:41 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdlib.h>
#include	"libft.h"

char	*ft_strdup(const char *src)
{
	char	*tab;
	int		j;
	int		i;

	i = 0;
	j = ft_strlen(src);
	tab = malloc(sizeof(char) * j + 1);
	if (!tab)
		return (0);
	while (i < j)
	{
		tab[i] = src[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
