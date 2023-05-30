/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:03:45 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 03:56:24 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/proto.h"

void	reset_keys(t_level *lvl)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		lvl->key[i] = 0;
		i++;
	}
}

void	draw_but(t_level *l)
{
	mlx_put_image_to_window(l->prm.mlx, l->prm.mlx_win, l->tx.pb, 143, 180);
	mlx_put_image_to_window(l->prm.mlx, l->prm.mlx_win, l->tx.qb, 143, 220);
	mlx_put_image_to_window(l->prm.mlx, l->prm.mlx_win, l->tx.logo, 15, 10);
}

void	draw_bcgk(t_level *lvl, t_vector start, t_vector end)
{
	t_vector	pos;

	pos.x = start.x;
	while (pos.x < end.x)
	{
		pos.y = start.y;
		while (pos.y < end.y)
		{
			if ((pos.x == pos.y * 3 || pos.y == pos.x * 3))
				draw_image(lvl, lvl->tx.empty[1], pos);
			else
				draw_image(lvl, lvl->tx.empty[0], pos);
			pos.y += lvl->tx.width;
		}
		pos.x += lvl->tx.width;
	}
}

int	menu_process(t_level *l)
{
	if (l->key[4] == 1)
	{
		if (l->player.pos.y == 220)
			exit(0);
		mlx_destroy_window(l->prm.mlx, l->prm.mlx_win);
		reset_keys(l);
		info("Starting...");
		start_menu(l);
	}
	if (l->key[1] == 1 || l->key[3] == 1)
	{
		if (l->player.pos.y == 220)
			l->player.pos.y = 180;
		else
			l->player.pos.y = 220;
		reset_keys(l);
	}
	draw_bcgk(l, vector(0, 0), vector(320, 320));
	draw_but(l);
	draw_player(l);
	return (0);
}

void	draw_menu(t_level *lvl)
{	
	lvl->player.pos.y = 180;
	lvl->player.pos.x = 110;
	lvl->prm.mlx_win = mlx_new_window(lvl->prm.mlx, 350, 350, NAME);
	draw_bcgk(lvl, vector(0, 0), vector(350, 350));
	draw_but(lvl);
	draw_player(lvl);
	mlx_hook(lvl->prm.mlx_win, 2, 0, key_press, lvl);
	mlx_hook(lvl->prm.mlx_win, 3, 0, key_release, lvl);
	mlx_loop_hook(lvl->prm.mlx, menu_process, lvl);
	mlx_loop(lvl->prm.mlx);
}
