/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:33:21 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/06 03:24:56 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	friction(t_level *l)
{
	if (l->player.vel.x > 0)
		l->player.vel.x -= 1;
	if (l->player.vel.y > 0)
		l->player.vel.y -= 1;
}

int	physics_process(t_level *l)
{
	friction(l);
	draw_level(l);
	draw_player(l);
	return (0);
}