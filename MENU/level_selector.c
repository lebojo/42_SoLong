/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:06 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/21 22:25:41 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void	draw_menu_level(t_level *l, t_vector *p)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (i < l->player.max_level)
			mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->ls_09[i + 1], p[i].x, p[i].y);
		else
			mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->ls_09_dark[i + 1], p[i].x, p[i].y);
	}
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
		if ((pp == 0 || pp == 1 || pp == 2) && pp + 6 <= l->player.max_level)
			pp += 6;
		else if (!(pp == 0 || pp == 1 || pp == 2))
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
		if ((pp == 6 || pp == 7 || pp == 8) && pp - 6 <= l->player.max_level)
			pp -= 6;
		else if (pp + 3 <= l->player.max_level)
			pp += 3;
		reset_keys(l);
	}
	l->player.pos = l->ls_pos[pp];
	l->player.pos.x -= l->texture.width;
	l->player.ls_position = pp;
}

void	launch_level(t_level *l)
{
	char	*path;

	if (l->key[4] == 1)
	{
		path = add_str("map/", ft_itoa(l->player.ls_position + 1));
		mlx_destroy_window(l->params.mlx, l->params.mlx_win);
		reset_keys(l);
		info(add_str("Starting level ", ft_itoa(l->player.ls_position)));
		start_level(l, add_str(path, ".ber"));
	}
}

int	level_selector_process(t_level *l)
{
	draw_bcgk(l, vector(0, 0), vector(350, 350));
	mlx_string_put(l->params.mlx, l->params.mlx_win, 10, 21, 0xFFFFFF, add_str("Actual time: ", ft_itoa(l->time)));
	draw_menu_level(l, l->ls_pos);
	player_position(l);
	draw_player(l);
	launch_level(l);
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
