/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:35:28 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/30 01:49:51 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = -1;
	if (!dst && !src)
		return (NULL);
	while (++i < n)
		((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
	return (dst);
}
