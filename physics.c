/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   physics.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:33:21 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/21 22:23:06 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	friction(t_level *l)
{
	static int	speed;

	if (speed == 2)
	{
		speed = 0;
		if (l->player.vel.x > 0)
			l->player.vel.x -= 1;
		if (l->player.vel.y > 0)
			l->player.vel.y -= 1;
		if (l->player.vel.x < 0)
			l->player.vel.x += 1;
		if (l->player.vel.y < 0)
			l->player.vel.y += 1;
		player_process(l);
	}
	move_player(l);
	speed++;
}

void	move_player(t_level *l)
{
	t_vector	new_pos;
	t_vector	edge;

	new_pos.x = l->player.pos.x + l->player.vel.x;
	new_pos.y = l->player.pos.y + l->player.vel.y;
	edge.x = l->data.size.x * l->texture.width;
	edge.y = l->data.size.y * l->texture.width;
	collision(l, new_pos, edge);
	l->player.pos.x += l->player.vel.x;
	l->player.pos.y += l->player.vel.y;
	collect_coins(l);
	exit_level(l);
}

int	physics_process(t_level *l)
{
	friction(l);
	draw_screen(l);
	hud_info(l, add_str("Coins: ", score_to_str(l)));
	return (0);
}