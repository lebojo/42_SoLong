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
	parse(file_path, level);
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
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, lvl->texture.empty, lvl->player.x, lvl->player.y);
	if ((keycode == 2 || keycode == 124
		|| keycode == 65363 || keycode == 100)
		&& lvl->player.x + 32 < (lvl->data.size.x - 1) * lvl->texture.width)
		lvl->player.x += 32;
	else if ((keycode == 0 || keycode == 123
		|| keycode == 65361 || keycode == 97)
		&& lvl->player.x - 32 >= lvl->texture.width)
		lvl->player.x -= 32;
	else if ((keycode == 13 || keycode == 126
		|| keycode == 65362 || keycode == 119)
		&& lvl->player.y - 32 > lvl->texture.width)
		lvl->player.y -= 32;
	else if ((keycode == 1 || keycode == 125
		|| keycode == 65364 || keycode == 115)
		&& lvl->player.y + 32 < lvl->data.size.y * lvl->texture.width)
		lvl->player.y += 32;
	else if (keycode == 53 || keycode == 65307)
		exit(0);
	printf("PLAYER: x->%d; y->%d\nSIZE: x->%d; y->%d\n-\n", lvl->player.x, lvl->player.y, lvl->data.size.x, lvl->data.size.y);
	mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, lvl->texture.player, lvl->player.x, lvl->player.y);
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
	mlx_key_hook(level.params.mlx_win, key_hook, &level);
	mlx_loop(level.params.mlx);
}
