/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/21 22:06:27 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include <mlx.h>

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

int	main(void)
{
	//t_level	level;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	//init(&level, argv[1]);
	return (0);
}
