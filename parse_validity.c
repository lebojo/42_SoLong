/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parse_validity.c								   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/20 09:01:39 by lebojo			#+#	#+#			 */
/*   Updated: 2023/02/20 10:24:38 by lebojo		   ###   ########.fr	   */
/*																			*/
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
		&& c != d.player)
		return (1);
	return (0);
}

void	cell_checker(t_level *l, t_vector *pos, t_requierements *req, int i)
{
	if (l->map[i] == '\n')
	{
		if (pos->x > l->data.size.x || pos->y > l->data.size.y)
			exit(error("Line size"));
		pos->x = 0;
		pos->y++;
		l->map_matrix[pos->y] = malloc(sizeof(char) * (l->data.size.x + 1));
		return ;
	}
	if (check_cell_exist(l->data, l->map[i]) == 1)
		exit (error("Cell"));
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
	l->map_matrix[pos->y][pos->x] = l->map[i];
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
	lvl.map_matrix = malloc(sizeof(char *) * lvl.data.size.y);
	lvl.map_matrix[0] = malloc(sizeof(char) * lvl.data.size.x);
	while (lvl.map[++i])
		cell_checker(&lvl, &pos, &req, i);
	if (check_req(req) == 1)
		return (error("Map incomplete"));
	info("Map ok!");
	return (0);
}
