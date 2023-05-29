/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/25 15:40:08 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	draw_player(t_level *l)
{
	t_vector	pos;
	int			f;

	pos = l->player.pos;
	f = l->texture.pf.nb;
	mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->texture.player[f], pos.x, pos.y);
	return (0);
}

int	draw_coins(t_level *l, t_params prm, t_vector pos)
{
	int			f;

	f = l->texture.cf.nb;
	mlx_put_image_to_window(prm.mlx, prm.mlx_win, l->texture.coins[f], pos.x, pos.y);
	return (0);
}

int	draw_cell(t_level *lvl, char c, t_params prm, t_vector pos)
{
	if (c == '\n')
		return (0);
	mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.empty, pos.x, pos.y);
	if (c == lvl->data.coins)
		draw_coins(lvl, prm, pos);
	else if (c == lvl->data.exit)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.exit, pos.x, pos.y);
	else if (c == lvl->data.wall && pos.y - 1 < lvl->player.pos.y)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.wall, pos.x, pos.y);
	return (1);
}

void	draw_wall(t_level *l)
{
	t_vector	pos;
	t_vector	cursor;

	set_vector(&cursor, l->player.pos.x / 32, l->player.pos.y / 32);
	set_vector(&pos, cursor.x * 32, (cursor.y + 1) * 32);
	while (cursor.y < l->data.size.y)
	{
		cursor.x = 1;
		pos.x = 0;
		while (cursor.x <= l->data.size.x)
		{
			if (l->map_matrix[cursor.y][cursor.x] == l->data.wall)
				mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->texture.wall, pos.x, pos.y);
			pos.x += l->texture.width;
			cursor.x++;
		}
		pos.y += l->texture.width;
		cursor.y++;
	}
}

void	draw_level(t_level *lvl)
{
	t_vector	pos;
	t_vector	cursor;

	set_vector(&cursor, 0, 0);
	set_vector(&pos, 0, lvl->texture.width);
	while (cursor.y < lvl->data.size.y)
	{
		cursor.x = 1;
		pos.x = 0;
		while (cursor.x <= lvl->data.size.x)
		{
			draw_cell(lvl, lvl->map_matrix[cursor.y][cursor.x], lvl->params, pos);
			pos.x += lvl->texture.width;
			cursor.x++;
		}
		pos.y += lvl->texture.width;
		cursor.y++;
	}
}

void	draw_hud(t_level *l)
{
	int	i;

	i = 0;
	while (i < l->data.size.x)
		mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->texture.blck, i++ * 32, 0);
}

void	draw_screen(t_level *l)
{
	animation_process(l);
	draw_level(l);
	draw_player(l);
	draw_wall(l);
}

void	draw_image(t_level *l, char *path, t_vector p)
{
	mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, path, p.x, p.y);
}
