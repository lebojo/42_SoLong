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
	level[0].data.collect = 'C';
	level[0].data.empty = '0';
	level[0].data.wall = '1';
	level[0].data.exit = 'E';
	level[0].data.player = 'P';
	level[0].map = parse(file_path);
	level[0].texture.collect = "./assets/coins.xpm";
	level[0].texture.empty = "./assets/floor.xpm";
	level[0].texture.wall = "./assets/wall.xpm";
	level[0].texture.exit = "./assets/enemy.xpm";
	level[0].texture.player = "./assets/player.xpm";
	level[0].texture.width = 32;
}

int	key_hook(int keycode, t_params *prm)
{
	static t_vector pos;

	if (keycode == 2 || keycode == 124
		|| keycode == 65363 || keycode == 100)
		pos.x += 32;
	else if (keycode == 0 || keycode == 123
		|| keycode == 65361 || keycode == 97)
		pos.x -= 32;
	else if (keycode == 13 || keycode == 126
		|| keycode == 65362 || keycode == 119)
		pos.y -= 32;
	else if (keycode == 1 || keycode == 125
		|| keycode == 65364 || keycode == 115)
		pos.y += 32;
	else if (keycode == 53 || keycode == 65307)
		exit(0);
	// ft_putstr_fd(ft_itoa(keycode), 0);
	// ft_putstr_fd("\n", 0);
	mlx_put_image_to_window(prm->mlx, prm->mlx_win, prm->img, pos.x, pos.y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_level		level;
	t_params	prm;
	int	img_width;
	int	img_height;

	if (argc != 2)
		return(error("Args"));
	info("Starting...");
	init_level(&level, argv[1]);
	info("Level init");
	prm.mlx = mlx_init();
	prm.mlx_win = mlx_new_window(prm.mlx, 1088, 192, NAME);
	info("Building level...");
	build_level(level, prm);
	prm.img = mlx_xpm_file_to_image(prm.mlx, level.texture.player, &img_width, &img_height);
	mlx_key_hook(prm.mlx_win, key_hook, &prm);
	mlx_loop(prm.mlx);
}
