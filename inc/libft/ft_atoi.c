/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 03:37:46 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/30 16:34:38 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_num_size(char *str);
int	char_to_int(char c);

int	str_num_size(char *str)
{
	int	size;

	size = 0;
	while (ft_isdigit(*str))
	{
		size++;
		str++;
	}
	return (size);
}

int	char_to_int(char c)
{
	return (c - '0');
}

int	ft_atoi(const char *str)
{
	int	res;
	int	res_sign;

	res = 0;
	res_sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			res_sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		res = res * 10 + char_to_int(*str);
		str++;
	}
	return (res_sign * res);
}
