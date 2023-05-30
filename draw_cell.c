/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 03:09:11 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	draw_player(t_level *l)
{
	t_vector	pos;
	int			f;

	pos = l->player.pos;
	f = l->tx.pf.nb;
	draw_image(l, l->tx.player[f], pos);
	return (0);
}

int	draw_coins(t_level *l, t_vector pos)
{
	int			f;

	f = l->tx.cf.nb;
	draw_image(l, l->tx.coins[f], pos);
	return (0);
}

int	draw_cell(t_level *lvl, char c, t_vector pos)
{
	if (c == '\n')
		return (0);
	if ((pos.x == pos.y * 3 || pos.y == pos.x * 2) && c == lvl->data.empty)
		draw_image(lvl, lvl->tx.empty[1], pos);
	else
		draw_image(lvl, lvl->tx.empty[0], pos);
	if (c == lvl->data.coins)
		draw_coins(lvl, pos);
	else if (c == lvl->data.exit)
		draw_image(lvl, lvl->tx.exit, pos);
	else if (c == lvl->data.wall && pos.y - 1 < lvl->player.pos.y)
		draw_image(lvl, lvl->tx.wall, pos);
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
				draw_image(l, l->tx.wall, pos);
			pos.x += l->tx.width;
			cursor.x++;
		}
		pos.y += l->tx.width;
		cursor.y++;
	}
}
