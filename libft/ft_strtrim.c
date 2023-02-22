/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 21:23:34 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/30 15:04:30 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		ii;
	int		j;

	i = 0;
	j = 0;
	ii = ft_strlen(s1);
	if (!ii)
		return (ft_strdup(""));
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (ii > 0 && ft_strchr(set, s1[ii]))
		ii--;
	if (i >= ii)
		res = malloc(sizeof(char));
	else
		res = malloc(sizeof(char) * (ii - i + 2));
	if (!res)
		return (0);
	while (i < ii + 1)
		res[j++] = s1[i++];
	res[j] = '\0';
	return (res);
}
