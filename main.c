/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/20 10:07:54 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"
#include <mlx.h>

int	init(t_level *level, char *file_path)
{
	level[0].data.collect = 'C';
	level[0].data.empty = '0';
	level[0].data.wall = '1';
	level[0].data.exit = 'E';
	level[0].data.player = 'P';
	level[0].map = parse(file_path);
	return (0);
}

int	main(int argc, char **argv)
{
	t_level	level;

	init(&level, argv[1]);
	return (0);
}
