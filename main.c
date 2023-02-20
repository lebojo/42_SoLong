/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 08:48:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/02/20 09:33:53 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

int	init(t_level *level)
{
	level[0].data.collect = 'C';
	level[0].data.empty = '0';
	level[0].data.wall = '1';
	level[0].data.exit = 'E';
	level[0].data.player = 'P';
	return (0);
}

int	main(int argc, char **argv)
{
	t_level	level;

	init(&level);
	level.map = parse(argv[1]);
	return (0);
}
