/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:06 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/21 18:41:45 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void	draw_menu_level(t_level *l, t_vector *p)
{
	int	i;

	i = -1;
	while (++i < 9)
		mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->ls_09[i + 1], p[i].x, p[i].y);
}

void	player_position(t_level *l)
{
	int	pp;

	pp = l->player.ls_position;
	if (l->key[0] == 1)
	{
		if (pp == 0 && l->player.max_level >= 8)
			pp = 8;
		else if (pp != 0)
			pp--;
		reset_keys(l);
	}
	if (l->key[1] == 1)
	{
		if (pp == 0 || pp == 1 || pp == 2)
			pp += 6;
		else
			pp -= 3;
		reset_keys(l);
	}
	if (l->key[2] == 1)
	{
		if (pp == 8)
			pp = 0;
		else if (pp + 1 < l->player.max_level)
			pp++;
		reset_keys(l);
	}
	if (l->key[3] == 1)
	{
		if (pp == 6 || pp == 7 || pp == 8)
			pp -= 6;
		else
			pp += 3;
		reset_keys(l);
	}
	l->player.pos = l->ls_pos[pp];
	l->player.pos.x -= l->texture.width;
	l->player.ls_position = pp;
}

int	level_selector_process(t_level *l)
{
	draw_bcgk(l, vector(0, 0), vector(350, 350));
	draw_menu_level(l, l->ls_pos);
	player_position(l);
	draw_player(l);
	return (0);
}

void	start_menu(t_level *l)
{
	l->player.pos.y = 180;
	l->player.pos.x = 110;
	l->params.mlx_win = mlx_new_window(l->params.mlx, 350, 350, NAME);
	draw_bcgk(l, vector(0, 0), vector(350, 350));
	init_ls(l);
	mlx_hook(l->params.mlx_win, 2, 0, key_press, l);
	mlx_hook(l->params.mlx_win, 3, 0, key_release, l);
	mlx_loop_hook(l->params.mlx, level_selector_process, l);
	mlx_loop(l->params.mlx);
}
/*TODO:
Faire les différentes pos pour le player, genre quand on touche
Genre et griser les 
*/