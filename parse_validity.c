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

int	parse_validity(t_level lvl)
{
	int				i;
	t_requierements	req; 

	i = -1;
	req.bool_coins = 0;
	req.bool_exit = 0;
	req.bool_player = 0;
	while (lvl.map[++i])
	{
		if (lvl.map[i] != lvl.data.coins
			&& lvl.map[i] != lvl.data.empty
			&& lvl.map[i] != lvl.data.exit
			&& lvl.map[i] != lvl.data.wall
			&& lvl.map[i] != lvl.data.player)
			return (1);
		if (lvl.map[i] == lvl.data.player && req.bool_player == 0)
			req.bool_player == 1;
		else if (lvl.map[i] == lvl.data.player && req.bool_player == 1)
			return (1);
		if (lvl.map[i] == lvl.data.coins && req.bool_coins == 0)
			req.bool_coins == 1;
		else if (lvl.map[i] == lvl.data.coins && req.bool_coins == 1)
			return (1);
		if (lvl.map[i] == lvl.data.exit && req.bool_exit == 0)
			req.bool_exit == 1;
		else if (lvl.map[i] == lvl.data.exit && req.bool_exit == 1)
			return (1);
	}	
}
//return 1 == error, 0 == good 🏆