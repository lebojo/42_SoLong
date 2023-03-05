/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:00:00 by jchapell          #+#    #+#             */
/*   Updated: 2022/12/21 00:40:26 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c, int rd)
{
	int	i;

	i = 0;
	if (rd == -1)
		return (0);
	if (!s || !s[i] || s == NULL)
		return (0);
	if (s[i] == (char)c)
		return (1);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		ii;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	ii = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[ii])
	{
		res[i] = s2[ii];
		ii++;
		i++;
	}
	res[i] = '\0';
	free((char *)s1);
	return (res);
}

char	*end_nullifier(char **s1, char *s2)
{
	char	*res;

	if (!s1 || !s2 || ft_strlen(*s1) + ft_strlen(s2) <= 0)
		return (0);
	s1[0] = ft_strjoin(s1[0], s2);
	res = parse_line(s1);
	return (res);
}

char	*get_afternewline(char *s1)
{
	char	*res;
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		i++;
	if (i == (int)ft_strlen(s1) || i == (int)ft_strlen(s1) - 1)
	{
		free(s1);
		return (0);
	}
	res = malloc(sizeof(char) * (ft_strlen(s1) - i));
	if (!res)
		return (0);
	while (s1 && s1[i] && s1[++i])
		res[ii++] = s1[i];
	res[ii] = '\0';
	free(s1);
	return (res);
}
