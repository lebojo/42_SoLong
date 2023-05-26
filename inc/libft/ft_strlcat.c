/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 03:44:29 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/29 03:51:12 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	i;
	unsigned int	result;

	size_dest = 0;
	i = 0;
	result = 0;
	while (dest[size_dest] != '\0')
		size_dest++;
	while (src[result] != '\0')
		result++;
	if (size <= size_dest)
		result += size;
	else
		result += size_dest;
	while (size_dest + 1 < size && src[i] != '\0')
	{
		dest[size_dest] = src[i];
		i++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (result);
}
