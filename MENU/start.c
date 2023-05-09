/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:45 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/09 04:33:16 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../proto.h"

void	reset_keys(t_level *lvl)
{
	int i;

	i = 0;
	while (i < 5)
	{
		lvl->key[i] = 0;
		i++;
	}
}

void draw_but(t_level *lvl)
{
	int		w;
	int		h;
	char	*play_but;
	char	*quit_but;

	play_but = mlx_xpm_file_to_image(lvl->params.mlx, "./assets/start_title.xpm", &w, &h);
	quit_but = mlx_xpm_file_to_image(lvl->params.mlx, "./assets/quit_title.xpm", &w, &h);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, play_but, 128, 160);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, quit_but, 128, 192);
}

void draw_bcgk(t_level *lvl, int px_width, int px_height)
{
	t_vector pos;

	pos.x = 0;
	while (pos.x < px_height)
	{
		pos.y = 0;
		while (pos.y < px_width)
		{
			mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, lvl->texture.empty, pos.x, pos.y);
			pos.y += lvl->texture.width;
		}
		pos.x += lvl->texture.width;
	}
	draw_but(lvl);
	draw_player(lvl);
}

void	menu_process(t_level *l)
{
	if (l->key[4] == 1)
	{
		if (l->player.pos.y == 160)
			exit(0);
		mlx_destroy_window(l->params.mlx, l->params.mlx_win);
		reset_keys(l);
		l->state = 1;
		info("Starting...");
		start_level(l, "map/default.ber");
	}
	if (l->key[1] == 1 || l->key[3] == 1 )
	{
		draw_bcgk(l, 320, 320);
		if (l->player.pos.y == 192)
			l->player.pos.y = 160;
		else
			l->player.pos.y = 192;
		reset_keys(l);
	}
}

void	draw_menu(t_level *lvl)
{	
	lvl->player.pos.y = 160;
	lvl->player.pos.x = 96;
	lvl->params.mlx_win = mlx_new_window(lvl->params.mlx, 320, 320, NAME);
	draw_bcgk(lvl, 320, 320);
	mlx_hook(lvl->params.mlx_win, 2, 0, key_press, lvl);
	mlx_hook(lvl->params.mlx_win, 3, 0, key_release, lvl);
	mlx_loop_hook(lvl->params.mlx, physics_process, lvl);
	mlx_loop(lvl->params.mlx);
}