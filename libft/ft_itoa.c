/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:09:58 by jchapell          #+#    #+#             */
/*   Updated: 2022/10/30 16:54:47 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int d)
{
	if (d < 0)
		d *= -1;
	return (d);
}

static int	ft_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nb = nb * ft_power(nb, power - 1);
	return (nb);
}

char	*ft_itoa(int n)
{
	int		nbzero;
	int		n2;
	char	*res;
	int		i;

	nbzero = 1;
	n2 = n;
	i = 0;
	if (n == -2147483648 && nbzero++)
		n2 = n / 10;
	while (ft_abs(n2) > 9 && nbzero++)
		n2 = n2 / 10;
	if (n == 0)
		return (ft_strdup("0"));
	res = ft_calloc(sizeof(char) * nbzero + 2, sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[i++] = '-';
	while (--nbzero >= 0)
	{
		res[i++] = ft_abs((n / ft_power(10, nbzero))) + 48;
		n = n - ((n / ft_power(10, nbzero)) * ft_power(10, nbzero));
	}
	return (res);
}
