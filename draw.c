/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/07 03:37:56 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	draw_player(t_level *l)
{
	t_vector	pos;

	pos = l->player.pos;
	mlx_put_image_to_window(l->params.mlx, l->params.mlx_win, l->texture.player, pos.x, pos.y);
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

void	draw_screen(t_level *l)
{
	draw_level(l);
	draw_player(l);
}

void draw_level(t_level *lvl)
{
	t_vector	pos;
	int			i;
	int			cel;

	i = 0;
	pos.x = 0;
	pos.y = lvl->texture.width;
	while (lvl->map[i])
	{
		cel = draw_cell(lvl, lvl->map[i], lvl->params, pos);
		if (cel != 0)
			pos.x += lvl->texture.width;
		else
		{
			pos.x = 0;
			pos.y += lvl->texture.width;
		}
		i++;
	}
}