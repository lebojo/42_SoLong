/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:30:06 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 04:25:04 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

int	check_req(t_requierements r)
{
	if (r.bool_exit == 0 || r.bool_player == 0 || r.bool_coins == 0)
		return (1);
	return (0);
}

int	check_cell_exist(t_data d, char c)
{
	if (c != d.coins
		&& c != d.empty
		&& c != d.exit
		&& c != d.wall
		&& c != d.player
		&& c != d.enemy)
		return (1);
	return (0);
}

void	new_line_check(t_level *l, t_vector pos, int i)
{
	if (pos.x != l->data.size.x)
		exit(error("Line size"));
	if (l->map[i - 1] != l->data.wall)
		exit(error("Border"));
}

void	cell_checker(t_level *l, t_vector *pos, t_requierements *req, int i)
{
	if (l->map[i] == '\n')
	{
		new_line_check(l, *pos, i);
		pos->x = 0;
		pos->y++;
		return ;
	}
	if (!l->map[i + 1] && pos->x + 1 != l->data.size.x)
		exit(error("Line size"));
	if (check_cell_exist(l->data, l->map[i]) == 1)
		exit(error("Cell"));
	if (l->map[i] == l->data.player && req->bool_player == 0)
		req->bool_player = 1;
	else if (l->map[i] == l->data.player && req->bool_player == 1)
		exit(error("2 players"));
	if (l->map[i] == l->data.coins && req->bool_coins == 0)
		req->bool_coins = 1;
	if (l->map[i] == l->data.exit && req->bool_exit == 0)
		req->bool_exit = 1;
	else if (l->map[i] == l->data.exit && req->bool_exit == 1)
		exit(error("2 exits"));
	if ((pos->x == 0 || pos->y == 0 || pos->y + 1 == l->data.size.y
			|| !l->map[i + 1]) && l->map[i] != '1')
		exit(error("Border"));
	pos->x++;
}

int	parse_validity(t_level lvl)
{
	int				i;
	t_vector		pos;
	t_requierements	req;

	i = -1;
	req.bool_coins = 0;
	req.bool_exit = 0;
	req.bool_player = 0;
	set_vector(&pos, 0, 0);
	info("Verifing map...");
	while (lvl.map[++i])
		cell_checker(&lvl, &pos, &req, i);
	if (check_req(req) == 1)
		return (error("Map incomplete"));
	info("Map ok!");
	return (0);
}
