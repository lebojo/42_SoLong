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

#include "proto.h"

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
	{
		if (lvl.map[i] == '\n')
		{
			i++;
			if (pos.x > lvl.data.size.x || pos.y > lvl.data.size.y)
				return (1);
			pos.x = 0;
			pos.y++;
		}
		if (check_cell_exist(lvl.data, lvl.map[i]) == 1)
			return (info("Cel don't exist"));
		if (lvl.map[i] == lvl.data.player && req.bool_player == 0)
			req.bool_player = 1;
		else if (lvl.map[i] == lvl.data.player && req.bool_player == 1)
			return (info("2 players"));
		if (lvl.map[i] == lvl.data.coins && req.bool_coins == 0)
			req.bool_coins = 1;
		if (lvl.map[i] == lvl.data.exit && req.bool_exit == 0)
			req.bool_exit = 1;
		else if (lvl.map[i] == lvl.data.exit && req.bool_exit == 1)
			return (info("2 exits"));
		pos.x++;
	}
	if (check_req(req) == 1)
		return (1);
	info("Map ok!");
	return (0);
}
//return 1 == error, 0 == good 🏆