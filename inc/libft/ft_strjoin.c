/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:20:18 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/29 21:02:48 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		ii;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	ii = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[ii])
	{
		res[i] = s2[ii];
		ii++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
