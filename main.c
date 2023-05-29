/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/20 08:48:18 by lebojo			#+#	#+#			 */
/*   Updated: 2023/04/02 00:10:40 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "proto.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_level		level;

	level.params.mlx = mlx_init();
	init_level(&level);
	if (argc >= 2)
	{
		info("Starting...");
		level.player.max_level = -1;
		reset_keys(&level);
		start_level(&level, argv[1]);
	}
	else
	{
		error("Args...");
		error("But ok i'll start the menu.");
		draw_menu(&level);
	}
}
