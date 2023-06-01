/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 04:49:55 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	draw_level(t_level *lvl)
{
	t_vector	pos;
	t_vector	cursor;

	set_vector(&cursor, 0, 0);
	set_vector(&pos, 0, lvl->tx.width);
	while (cursor.y < lvl->data.size.y)
	{
		cursor.x = 1;
		pos.x = 0;
		while (cursor.x <= lvl->data.size.x)
		{
			draw_cell(lvl, lvl->map_matrix[cursor.y][cursor.x], pos);
			pos.x += lvl->tx.width;
			cursor.x++;
		}
		pos.y += lvl->tx.width;
		cursor.y++;
	}
}

void	draw_hud(t_level *l)
{
	int	i;

	i = 0;
	while (i < l->data.size.x)
		draw_image(l, l->tx.blck, vector(i++ *32, 0));
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
	mlx_put_image_to_window(l->prm.mlx, l->prm.mlx_win, path, p.x, p.y);
}
