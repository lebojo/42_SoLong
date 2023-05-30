/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 04:20:14 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 04:21:09 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

t_vector	vector(int x, int y)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	return (res);
}

void	set_vector(t_vector *v, int x, int y)
{
	v->x = x;
	v->y = y;
}

int	vector_collide(t_vector v1, t_vector v2, int width)
{
	int	v1_r;
	int	v1_b;
	int	v2_r;
	int	v2_b;

	v1_r = v1.x + width - 2;
	v1_b = v1.y + width - 2;
	v2_r = v2.x + width - 5;
	v2_b = v2.y + 20;
	set_vector(&v1, v1.x + 2, v1.y + 2);
	set_vector(&v2, v2.x + 5, v2.y + 15);
	if (v1.x <= v2_r && v1_r >= v2.x && v1.y <= v2_b && v1_b >= v2.y)
		return (1);
	return (0);
}
