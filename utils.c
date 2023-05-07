/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:34:12 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/07 03:10:00 by jchapell         ###   ########.fr       */
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
	int v2_right = v2.x + width - 5;
	int v2_bot = v2.y + width - 5;
	
	if (v1.x < v2_right && v1_right > v2.x + 5 && v1.y < v2_bot && v1_bot > v2.y + 5)
		return (1);
	return (0);
}
