/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hefurrer <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:15:46 by hefurrer          #+#    #+#             */
/*   Updated: 2022/10/13 13:38:59 by hefurrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	<stdlib.h>
#include	<stddef.h>
#include	"libft.h"

static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_reslen(char const *s, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (len)
		i = len - 1;
	while (ft_isinset(s[i], set) && len)
	{
		len--;
		i--;
	}
	i = 0;
	while (ft_isinset(s[i], set) && s[i] && len)
	{
		len--;
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	len = ft_reslen(s1, set);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (ft_isinset(s1[i], set) && s1[i])
		i++;
	j = 0;
	while (j < len && s1[i])
	{
		res[j] = s1[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}
