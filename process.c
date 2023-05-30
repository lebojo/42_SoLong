/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:53:34 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	physics_process(t_level *l)
{
	friction(l);
	draw_screen(l);
	hud_info(l, add_str("Coins: ", score_to_str(l)));
	return (0);
}

void	player_process(t_level *l)
{
	int	max_speed;

	max_speed = 6;
	if (l->player.vel.x < max_speed && l->player.vel.x > -max_speed)
	{
		if (l->key[0] == 1)
			l->player.vel.x -= 2;
		if (l->key[2] == 1)
			l->player.vel.x += 2;
	}
	if (l->player.vel.y < max_speed && l->player.vel.y > -max_speed)
	{
		if (l->key[1] == 1)
			l->player.vel.y -= 2;
		if (l->key[3] == 1)
			l->player.vel.y += 2;
	}
}

void	animation_process(t_level *l)
{
	if (l->time % 3 == 0)
		anim_coins(l);
	if (l->time % 3 == 0)
		anim_player(l);
	l->time++;
}

int	level_selector_process(t_level *l)
{
	char	*at;

	at = add_str("Actual time: ", ft_itoa(l->time));
	draw_bcgk(l, vector(0, 0), vector(350, 350));
	mlx_string_put(l->prm.mlx, l->prm.mlx_win, 120, 93, 0x000000, at);
	mlx_string_put(l->prm.mlx, l->prm.mlx_win, 120, 91, 0xFFFFFF, at);
	draw_menu_level(l, l->ls_pos);
	player_position(l);
	draw_player(l);
	launch_level(l);
	return (0);
}
