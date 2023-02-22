/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/22 01:08:14 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include <mlx.h>

#include <stdio.h>

// int	init(t_level *level, char *file_path)
// {
// 	level[0].data.collect = 'C';
// 	level[0].data.empty = '0';
// 	level[0].data.wall = '1';
// 	level[0].data.exit = 'E';
// 	level[0].data.player = 'P';
// 	level[0].map = parse(file_path);
// 	return (0);
// }

int	key_hook(int keycode, t_params *prm)
{
	static int	x_pos = 0;
	static int	y_pos = 0;
	if (keycode == 2 || keycode == 124)
		x_pos += 50;
	else if (keycode == 0 || keycode == 123)
		x_pos -= 50;
	else if (keycode == 13 || keycode == 126)
		y_pos -= 50;
	else if (keycode == 1 || keycode == 125)
		y_pos += 50;
	mlx_put_image_to_window(prm[0].mlx, prm[0].mlx_win, prm[0].img, x_pos, y_pos);
	return (0);
}

int	main(void)
{
	//t_level	level;
	t_params 	prm;
	char		*relative_path = "./mario.xpm";
	int			img_width;
	int			img_height;
	
	prm.mlx = mlx_init();
	prm.mlx_win = mlx_new_window(prm.mlx, 1920, 1080, "SoLong 2023 edition");
	prm.img = mlx_xpm_file_to_image(prm.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(prm.mlx, prm.mlx_win, prm.img, 0, 0);
	mlx_key_hook(prm.mlx_win, key_hook, &prm);
	mlx_loop(prm.mlx);
	//init(&level, argv[1]);
}
