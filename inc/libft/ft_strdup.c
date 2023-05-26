/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:43:11 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/29 23:00:24 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
