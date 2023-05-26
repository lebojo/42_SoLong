/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/22 01:10:43 by lebojo           ###   ########.fr       */
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

int draw_cell(t_level *lvl, char c, t_params prm, t_vector pos)
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

void draw_level(t_level *lvl)
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

void	draw_around_player(t_level *l)
{
	t_vector	pos;
	t_vector	cursor;
	t_vector	pp; // = player pos
	int			i;

	pp = l->player.pos;
	set_vector(&cursor, pp.x / 32, (pp.y - 32) / 32);
	set_vector(&pos, near_32(pp.x - 32), near_32(pp.y - 32));
	i = 0;
	while (i < 9)
	{
		draw_cell(l, l->map_matrix[cursor.y][cursor.x], l->params, pos);
		if (i == 2 || i == 5)
		{
			cursor.x = pp.x / 32;
			pos.x = near_32(pp.x - 32);
			pos.y += 32;
			cursor.y++;
		}
		else
		{
			cursor.x++;
			pos.x += 32;
		}
		i++;
	}
}

void draw_hud(t_level *l)
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