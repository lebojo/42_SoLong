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
	level->data.collect = 'C';
	level->data.empty = '0';
	level->data.wall = '1';
	level->data.exit = 'E';
	level->data.player = 'P';
	level->data.size.x = -1;
	level->data.size.y = 1;
	parse(file_path, level);
	level->texture.collect = "./assets/coins.xpm";
	level->texture.empty = "./assets/floor.xpm";
	level->texture.wall = "./assets/wall.xpm";
	level->texture.exit = "./assets/enemy.xpm";
	level->texture.player = "./assets/player.xpm";
	level->texture.width = 32;
	info("Level initiated");
}

int	key_hook(int keycode, t_params *prm)
{
	mlx_put_image_to_window(prm->mlx, prm->mlx_win, prm->floor, prm->pos->x, prm->pos->y);
	if (keycode == 2 || keycode == 124
		|| keycode == 65363 || keycode == 100)
		prm->pos->x += 32;
	else if (keycode == 0 || keycode == 123
		|| keycode == 65361 || keycode == 97)
		prm->pos->x -= 32;
	else if (keycode == 13 || keycode == 126
		|| keycode == 65362 || keycode == 119)
		prm->pos->y -= 32;
	else if (keycode == 1 || keycode == 125
		|| keycode == 65364 || keycode == 115)
		prm->pos->y += 32;
	else if (keycode == 53 || keycode == 65307)
		exit(0);
	// ft_putstr_fd(ft_itoa(keycode), 0);
	// ft_putstr_fd("\n", 0);
	mlx_put_image_to_window(prm->mlx, prm->mlx_win, prm->img, prm->pos->x, prm->pos->y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_level		level;
	t_params	prm;
	int			img_width;
	int			img_height;

	if (argc != 2)
		return(error("Args"));
	info("Starting...");
	init_level(&level, argv[1]);
	prm.mlx = mlx_init();
	prm.mlx_win = mlx_new_window(prm.mlx, level.data.size.x * level.texture.width, level.data.size.y * level.texture.width, NAME);
	info("Building level...");
	build_level(&level, prm);
	prm.img = mlx_xpm_file_to_image(prm.mlx, level.texture.player, &img_width, &img_height);
	prm.floor = mlx_xpm_file_to_image(prm.mlx, level.texture.empty, &img_width, &img_height);
	prm.pos = &level.player;
	mlx_key_hook(prm.mlx_win, key_hook, &prm);
	mlx_loop(prm.mlx);
}
