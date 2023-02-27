/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/27 18:02:49 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include <mlx.h>
#include "libft/libft.h"

#include <stdio.h>

int	init_level(t_level *level)
{
	level[0].data.collect = 'C';
	level[0].data.empty = '0';
	level[0].data.wall = '1';
	level[0].data.exit = 'E';
	level[0].data.player = 'P';
	//level[0].map = parse(file_path); à rajouter avec argv1
	level[0].texture.collect = "./assets/coins.xpm";
	level[0].texture.empty = "./assets/floor.xpm";
	level[0].texture.wall = "./assets/wall.xpm";
	level[0].texture.exit = "./assets/enemy.xpm";
	level[0].texture.player = "./assets/player.xpm";
	level[0].texture.width = 16;
	return (0);
}

int	key_hook(int keycode, t_params *prm)
{
	static int	x_pos = 0;
	static int	y_pos = 0;

	if (keycode == 2 || keycode == 124
		|| keycode == 65363 || keycode == 100)
		x_pos += 16;
	else if (keycode == 0 || keycode == 123
		|| keycode == 65361 || keycode == 97)
		x_pos -= 16;
	else if (keycode == 13 || keycode == 126
		|| keycode == 65362 || keycode == 119)
		y_pos -= 16;
	else if (keycode == 1 || keycode == 125
		|| keycode == 65364 || keycode == 115)
		y_pos += 16;
	else if (keycode == 65307)
		exit(0);
	ft_putstr_fd(ft_itoa(keycode), 0);
	ft_putstr_fd("\n", 0);
	mlx_put_image_to_window(prm[0].mlx, prm[0].mlx_win, prm[0].img, x_pos, y_pos);
	return (0);
}

int	main(void)
{
	t_level		level;
	t_params	prm;
	int			img_width;
	int			img_height;

	init_level(&level);
	prm.mlx = mlx_init();
	prm.mlx_win = mlx_new_window(prm.mlx, 160, 160, "SoLong 2023 edition");
	prm.img = mlx_xpm_file_to_image(prm.mlx, level.texture.player, &img_width, &img_height);
	mlx_put_image_to_window(prm.mlx, prm.mlx_win, prm.img, 0, 0);
	mlx_key_hook(prm.mlx_win, key_hook, &prm);
	mlx_loop(prm.mlx);
}
