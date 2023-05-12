/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:34:12 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/12 23:43:10 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	set_vector(t_vector *v, int x, int y)
{
	v->x = x;
	v->y = y;	
}

int	vector_collide(t_vector v1, t_vector v2, int width)
{
	int	v1_right = v1.x + width;
	int v1_bot = v1.y + width;
	int v2_right = v2.x + width - 10;
	int v2_bot = v2.y + width - 5;
	
	if (v1.x < v2_right && v1_right > v2.x + 10 && v1.y < v2_bot && v1_bot > v2.y + 5)
		return (1);
	return (0);
}

int	invert(int d)
{
	if (d == 1)
		return (0);
	return (0);
}

void	erase_coins(t_level *l, t_vector pos_erase)
{
	pos_erase.x = (pos_erase.x / l->texture.width) + 1;
	pos_erase.y = (pos_erase.y / l->texture.width) - 1;
	l->map_matrix[pos_erase.y][pos_erase.x] = l->data.empty;
}

t_vector vector(int x, int y)
{
	t_vector res;

	res.x = x;
	res.y = y;
	return (res);
}