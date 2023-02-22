/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 04:04:24 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/30 01:14:47 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	ii;
	size_t	slen;
	char	*res;

	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	slen = (size_t)ft_strlen(s);
	if (slen < len)
		res = malloc(sizeof(*s) * (slen - start + 1));
	else
		res = malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	ii = 0;
	while (s[++i])
		if (i >= start && ii < len)
			res[ii++] = s[i];
	res[ii] = 0;
	return (res);
}
