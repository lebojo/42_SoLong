/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:15:19 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/06 03:25:07 by jchapell         ###   ########.fr       */
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

// void	move_draw(t_level *lvl, char dir, char id)
// {
// 	t_vector	m_pos;

// 	if (id == lvl->data.exit)
// 	{
// 		if (lvl->player.coins >= lvl->data.coins_max)
// 			exit(info("You win!"));
// 		else
// 			info("You should'nt die broke");
// 		return ;
// 	}
// 	if (dir == 'R' && id != lvl->data.wall)
// 			lvl->player.pos.x += lvl->player.vel;
// 	else if (dir == 'L' && id != lvl->data.wall)
// 		lvl->player.pos.x -= lvl->player.vel;
// 	else if (dir == 'U' && id != lvl->data.wall)
// 		lvl->player.pos.y -= lvl->player.vel;
// 	else if (dir == 'D' && id != lvl->data.wall)
// 		lvl->player.pos.y += lvl->player.vel;
// 	m_pos = pixel_to_matrix(lvl->player.pos);
// 	if (id == lvl->data.collect)
// 	{
// 		lvl->map_matrix[m_pos.y][m_pos.x] = lvl->data.empty;
// 		lvl->player.coins++;
// 		print_score(lvl->player.coins, lvl->data.coins_max);
// 	}
// }

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