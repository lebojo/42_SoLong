/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:45 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/05 05:48:10 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void draw_bcgk(t_level lvl, int px_width, int px_height)
{
	t_vector pos;

	pos.x = 0;
	while (pos.x < px_height)
	{
		pos.y = 0;
		while (pos.y < px_width)
		{
			mlx_put_image_to_window(lvl.params.mlx, lvl.params.mlx_win, lvl.texture.empty, pos.x, pos.y);
			pos.y += lvl.texture.width;
		}
		pos.x += lvl.texture.width;
	}
}

int	menu_key_hook(int keycode, t_level *lvl)
{
	char	dir;
	
	if (keycode == 36)
	{
		if (lvl->player.pos.y == 192)
			exit(0);
		mlx_destroy_window(lvl->params.mlx, lvl->params.mlx_win);
		start_level(lvl, "map/default.ber");
	}
	dir = int_to_dir(keycode);
	if (dir == 'U' || dir == 'D')
	{
		mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, lvl->texture.empty, 96, lvl->player.pos.y);
		if (lvl->player.pos.y == 192)
		{
			lvl->player.pos.y = 160;
		}
		else
		{
			lvl->player.pos.y = 192;
		}
	}
	return (0);
}

void	draw_menu(t_level *lvl)
{
	int		w;
	int		h;
	char	*play_but;
	char	*quit_but;
	
	lvl->player.pos.y = 160;
	lvl->player.pos.x = 96;
	lvl->params.mlx_win = mlx_new_window(lvl->params.mlx, 320, 320, NAME);
	draw_bcgk(*lvl, 320, 320);
	draw_player(lvl);
	play_but = mlx_xpm_file_to_image(lvl->params.mlx, "./assets/start_title.xpm", &w, &h);
	quit_but = mlx_xpm_file_to_image(lvl->params.mlx, "./assets/quit_title.xpm", &w, &h);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, play_but, 128, 160);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, quit_but, 128, 192);
	mlx_key_hook(lvl->params.mlx_win, menu_key_hook, lvl);
}

/*
MEC, en fait faut faire une fenêtre pour le menu,
avec un sélection de niveau, et après ça créer une nouvelle
fenêtre.f
*/