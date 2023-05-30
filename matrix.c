/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:33:58 by jchapell          #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	add_collision(t_level *l, t_vector pos, int nb_col)
{
	t_vector	*new_map;
	int			i;

	i = 0;
	set_vector(&pos, pos.x * l->tx.width, (pos.y + 1) * l->tx.width);
	new_map = malloc(sizeof(t_vector) * (nb_col + 1));
	if (nb_col > 1)
	{
		i = -1;
		while (++i < nb_col)
			new_map[i] = l->collision_map[i];
		free(l->collision_map);
	}
	new_map[i] = pos;
	l->collision_map = new_map;
}

void	add_coins(t_level *l, t_vector pos, int nb_coins)
{
	t_vector	*new_map;
	int			i;

	i = 0;
	set_vector(&pos, pos.x * l->tx.width, (pos.y + 1) * l->tx.width);
	new_map = malloc(sizeof(t_vector) * (nb_coins + 1));
	if (nb_coins > 1)
	{
		i = -1;
		while (++i < nb_coins - 1)
			new_map[i] = l->map_c[i];
		free(l->map_c);
	}
	new_map[i] = pos;
	l->map_c = new_map;
}
