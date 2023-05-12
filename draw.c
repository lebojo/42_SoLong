/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/13 00:03:47 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	draw_player(t_level *l)
{
	t_vector	pos;
	static int	i;
	static int	ii;

	pos = l->player.pos;
	if (i >= 3)
		i = 0;
	if (ii == 5)
	{
		i++;
		ii = 0;
	}
	ii++;
	mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->texture.player[i], pos.x, pos.y);
	return (0);
}

int draw_cell(t_level *lvl, char c, t_params prm, t_vector pos)
{
	if (c == '\n')
		return (0);
	if (c == lvl->data.collect)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.collect, pos.x, pos.y);
	else if (c == lvl->data.empty || c == lvl->data.player)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.empty, pos.x, pos.y);
	else if (c == lvl->data.exit)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.exit, pos.x, pos.y);
	else if (c == lvl->data.wall)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.wall, pos.x, pos.y);
	return (1);
}


void draw_level_behind(t_level *lvl)
{
	t_vector	pos;
	t_vector	cursor;
	int			cel;

	set_vector(&cursor, 0, 0);
	set_vector(&pos, 0, lvl->texture.width);
	while (cursor.y < lvl->player.pos.y / 32)
	{
		cursor.x = 1;
		pos.x = 0;
		while (cursor.x <= lvl->data.size.x)
		{
			cel = draw_cell(lvl, lvl->map_matrix[cursor.y][cursor.x], lvl->params, pos);
			pos.x += lvl->texture.width;
			cursor.x++;
		}
		pos.y += lvl->texture.width;
		cursor.y++;
	}
}

void draw_level_front(t_level *lvl)
{
	t_vector	pos;
	t_vector	cursor;
	int			cel;

	set_vector(&cursor, 0, lvl->data.size.y - 1);
	set_vector(&pos, 0, lvl->data.size.y * 32);
	while (cursor.y >= lvl->player.pos.y / 32)
	{
		cursor.x = 1;
		pos.x = 0;
		while (cursor.x <= lvl->data.size.x)
		{
			cel = draw_cell(lvl, lvl->map_matrix[cursor.y][cursor.x], lvl->params, pos);
			pos.x += lvl->texture.width;
			cursor.x++;
		}
		pos.y -= lvl->texture.width;
		cursor.y--;
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
	draw_level_behind(l);
	draw_hud(l);
	draw_player(l);
	draw_level_front(l);
}