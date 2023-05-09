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

void	init_level(t_level *level)
{
	int			img_width;
	int			img_height;

	level->state = 0;
	level->data.collect = 'C';
	level->data.empty = '0';
	level->data.wall = '1';
	level->data.exit = 'E';
	level->data.player = 'P';
	set_vector(&level->data.size, -1, 1);
	level->data.coins_max = 0;
	level->player.coins = 0;
	set_vector(&level->player.vel, -1, 0);
	level->player.pos.x = -1;
	level->nb_col = 0;
	level->collision_map = malloc(sizeof(t_vector));
	level->texture.player[0] = mlx_xpm_file_to_image(level->params.mlx, "./assets/player_frames/player1.xpm", &img_width, &img_height);
	level->texture.player[1] = mlx_xpm_file_to_image(level->params.mlx, "./assets/player_frames/player2.xpm", &img_width, &img_height);
	level->texture.player[2] = mlx_xpm_file_to_image(level->params.mlx, "./assets/player_frames/player3.xpm", &img_width, &img_height);
	level->texture.player[3] = mlx_xpm_file_to_image(level->params.mlx, "./assets/player_frames/player4.xpm", &img_width, &img_height);
	level->texture.collect = mlx_xpm_file_to_image(level->params.mlx, "./assets/coins.xpm", &img_width, &img_height);
	level->texture.empty = mlx_xpm_file_to_image(level->params.mlx, "./assets/floor.xpm", &img_width, &img_height);
	level->texture.wall = mlx_xpm_file_to_image(level->params.mlx, "./assets/wall.xpm", &img_width, &img_height);
	level->texture.exit = mlx_xpm_file_to_image(level->params.mlx, "./assets/enemy.xpm", &img_width, &img_height);
	level->texture.width = 32;
	info("Game initiated");
}

int	main(int argc, char **argv)
{
	t_level		level;

	level.params.mlx = mlx_init();
	init_level(&level);
	if (argc >= 2)
	{
		level.state = 1;
		info("Starting...");
		start_level(&level, argv[1]);
	}
	else
	{
		error("Args...");
		error("But ok i'll start the menu.");
		draw_menu(&level);
	}
}
