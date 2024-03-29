/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:41:39 by lebojo            #+#    #+#             */
/*   Updated: 2023/06/01 18:42:34 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	coin_check(t_vector pos, t_vector max, char **map)
{
	if (map[pos.y][pos.x] == 'P')
		return (1);
	if (pos.y + 1 > max.y || pos.x + 1 > max.x
		|| pos.y < 0 || pos.x < 0
		|| map[pos.y][pos.x] == '1')
		return (0);
	if (map[pos.y][pos.x] == '0' || map[pos.y][pos.x] == 'C')
	{
		map[pos.y][pos.x] = 'X';
		if (coin_check(vector(pos.x + 1, pos.y), max, map) == 1
			|| coin_check(vector(pos.x, pos.y + 1), max, map) == 1
			|| coin_check(vector(pos.x - 1, pos.y), max, map) == 1
			|| coin_check(vector(pos.x, pos.y - 1), max, map) == 1)
		{
			return (1);
		}
	}
	return (0);
}

int	exit_check(t_vector pos, t_vector max, char **map)
{
	if (map[pos.y][pos.x] == 'P')
		return (1);
	if (pos.y + 1 > max.y || pos.x + 1 > max.x
		|| pos.y < 0 || pos.x < 0
		|| map[pos.y][pos.x] == '1')
		return (0);
	if (map[pos.y][pos.x] == '0'
		|| map[pos.y][pos.x] == 'C' || map[pos.y][pos.x] == 'E')
	{
		map[pos.y][pos.x] = 'X';
		if (coin_check(vector(pos.x + 1, pos.y), max, map) == 1
			|| coin_check(vector(pos.x, pos.y + 1), max, map) == 1
			|| coin_check(vector(pos.x - 1, pos.y), max, map) == 1
			|| coin_check(vector(pos.x, pos.y - 1), max, map) == 1)
		{
			return (1);
		}
	}
	return (0);
}

char	**map_extract(t_level *l)
{
	int			i;
	char		cel;
	t_vector	pos;
	char		**res;

	i = -1;
	pos.x = 0;
	pos.y = 0;
	res = malloc(sizeof(char *) * l->data.size.y);
	res[0] = malloc(sizeof(char) * l->data.size.x + 1);
	while (l->map[++i])
	{
		cel = l->map[i];
		if (cel != '\n')
			pos.x += 1;
		else
		{
			pos.x = 0;
			pos.y += 1;
			res[pos.y] = malloc(sizeof(char) * (l->data.size.x + 1));
			continue ;
		}
		res[pos.y][pos.x] = cel;
	}
	return (res);
}

int	can_collect_coins(t_level *l)
{
	int			i;
	char		**cpy;
	int			result;
	t_vector	pos;

	i = 0;
	while (i < l->data.coins_max)
	{
		cpy = map_extract(l);
		set_vector(&pos, (l->map_c[i].x / 32) + 1, (l->map_c[i].y / 32) - 1);
		result = coin_check(pos, l->data.size, cpy);
		free_matrix(l->data.size.y, cpy);
		if (result != 1)
			return (0);
		i++;
	}
	info("Coins ok!");
	return (1);
}

void	level_validity(t_level *l)
{
	char	**cpy;

	cpy = map_extract(l);
	if (can_collect_coins(l) == 0)
	{
		free_matrix(l->data.size.y, cpy);
		exit(error("Coin(s) can't be collected"));
	}
	if (!exit_check(l->exit_mx, l->data.size, cpy))
	{
		free_matrix(l->data.size.y, cpy);
		exit(error("Exit not reachable"));
	}
	free_matrix(l->data.size.y, cpy);
}
