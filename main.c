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

void	init_level(t_level *level, char *file_path)
{
	int			img_width;
	int			img_height;

	level->data.collect = 'C';
	level->data.empty = '0';
	level->data.wall = '1';
	level->data.exit = 'E';
	level->data.player = 'P';
	level->data.size.x = -1;
	level->data.size.y = 1;
	level->data.coins_max = 0;
	level->player.coins = 0;
	parse(file_path, level);
	level->map_matrix = malloc(sizeof(char *) * level->data.size.y);
	level->texture.collect = mlx_xpm_file_to_image(level->params.mlx, "./assets/coins.xpm", &img_width, &img_height);
	level->texture.empty = mlx_xpm_file_to_image(level->params.mlx, "./assets/floor.xpm", &img_width, &img_height);
	level->texture.wall = mlx_xpm_file_to_image(level->params.mlx, "./assets/wall.xpm", &img_width, &img_height);
	level->texture.exit = mlx_xpm_file_to_image(level->params.mlx, "./assets/enemy.xpm", &img_width, &img_height);
	level->texture.player = mlx_xpm_file_to_image(level->params.mlx, "./assets/player.xpm", &img_width, &img_height);
	level->texture.width = 32;
	info("Level initiated");
}

int	key_hook(int keycode, t_level *lvl)
{
	char	dir;
	char	id;

	dir = int_to_dir(keycode);
	id = move_id(lvl->player.pos, lvl->map_matrix, dir);
	move_draw(lvl, dir, id);
	return (0);
}

int	main(int argc, char **argv)
{
	t_level		level;

	if (argc != 2)
		return(error("Args"));
	info("Starting...");
	level.params.mlx = mlx_init();
	init_level(&level, argv[1]);
	level.params.mlx_win = mlx_new_window(level.params.mlx, level.data.size.x * level.texture.width, (level.data.size.y + 1) * level.texture.width, NAME);
	info("Building level...");
	build_level(&level);
	draw_menu(&level);
	mlx_key_hook(level.params.mlx_win, key_hook, &level);
	mlx_loop(level.params.mlx);
}
