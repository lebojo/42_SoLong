/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:41:39 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/17 19:22:37 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int coin_check(t_vector pos, t_vector max, char **map)
{
    if (map[pos.y][pos.x] == 'P')
        return (2);
    if (pos.y > max.y || pos.x > max.x || pos.y < 1 || pos.x < 1 || map[pos.y][pos.x] == '1')
        return (0);

    if (map[pos.y][pos.x] == '0' || map[pos.y][pos.x] == 'C')
    {
        map[pos.y][pos.x] = 'X';
        if (coin_check(vector(pos.x + 1, pos.y), max, map) == 2 ||
            coin_check(vector(pos.x, pos.y + 1), max, map) == 2 ||
            coin_check(vector(pos.x - 1, pos.y), max, map) == 2 ||
            coin_check(vector(pos.x, pos.y - 1), max, map) == 2)
        {
            return (2);
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
	
	i = 0;
	pos.x = 0;
	pos.y = 0;
	res = malloc(sizeof(char *) * l->data.size.y);
	res[0] = malloc(sizeof(char) * l->data.size.x + 1);
	while (l->map[i])
	{
		cel = l->map[i];
		if (cel != '\n')
			pos.x += 1;
		else
		{
			pos.x = 0;
			pos.y += 1;
			res[pos.y] = malloc(sizeof(char) * (l->data.size.x + 1));
			i++;
			continue ;
		}
		res[pos.y][pos.x] = cel;
		i++;
	}
	info("Matrix copied!");
	return (res);
}

int can_collect_coins(t_level *l)
{
    int i;

    i = 0;
    while (i < l->data.coins_max)
    {
		char **cpy = map_extract(l);
        int result = coin_check(vector(l->coins_map[i].x / 32, (l->coins_map[i].y / 32) - 1), l->data.size, cpy);
        if (result != 2)
		{
            return (0);
		}
        
        i++;
    }
	info("Coins ok!");
    return (1);
}
