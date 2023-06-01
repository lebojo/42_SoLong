/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:22:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/06/01 03:00:27 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	init_player_frames(t_level *l)
{
	l->tx.player[0] = path_to_image(l, "./assets/player_frames/player_1.xpm");
	l->tx.player[1] = path_to_image(l, "./assets/player_frames/player_2.xpm");
	l->tx.player[2] = path_to_image(l, "./assets/player_frames/player_3.xpm");
	l->tx.player[3] = path_to_image(l, "./assets/player_frames/player_4.xpm");
	l->tx.pf.nb = 0;
	l->tx.pf.max = 3;
}

void	init_coins_frames(t_level *l)
{
	l->tx.coins[0] = path_to_image(l, "./assets/coins_frames/coins_1.xpm");
	l->tx.coins[1] = path_to_image(l, "./assets/coins_frames/coins_2.xpm");
	l->tx.coins[2] = path_to_image(l, "./assets/coins_frames/coins_3.xpm");
	l->tx.coins[3] = path_to_image(l, "./assets/coins_frames/coins_4.xpm");
	l->tx.coins[4] = path_to_image(l, "./assets/coins_frames/coins_5.xpm");
	l->tx.coins[5] = path_to_image(l, "./assets/coins_frames/coins_6.xpm");
	l->tx.coins[6] = path_to_image(l, "./assets/coins_frames/coins_7.xpm");
	l->tx.coins[7] = path_to_image(l, "./assets/coins_frames/coins_8.xpm");
	l->tx.cf.nb = 0;
	l->tx.cf.max = 7;
}

void	init_tx(t_level *l)
{
	init_player_frames(l);
	init_coins_frames(l);
	l->tx.empty[0] = path_to_image(l, "./assets/floor.xpm");
	l->tx.empty[1] = path_to_image(l, "./assets/floor2.xpm");
	l->tx.wall = path_to_image(l, "./assets/wall.xpm");
	l->tx.enemy = path_to_image(l, "./assets/enemy.xpm");
	l->tx.exit = path_to_image(l, "./assets/exit.xpm");
	l->tx.blck = path_to_image(l, "./assets/blck.xpm");
	l->tx.pb = path_to_image(l, "./assets/start_title.xpm");
	l->tx.qb = path_to_image(l, "./assets/quit_title.xpm");
	l->tx.logo = path_to_image(l, "./assets/logo.xpm");
	l->tx.width = 32;
}

void	init_level(t_level *l)
{
	l->time = 0;
	l->data.coins = 'C';
	l->data.empty = '0';
	l->data.wall = '1';
	l->data.exit = 'E';
	l->data.player = 'P';
	l->data.enemy = 'V';
	set_vector(&l->data.size, -1, 1);
	l->data.coins_max = 0;
	l->player.coins = 0;
	l->player.move = 0;
	set_vector(&l->player.vel, 0, 0);
	l->player.pos.x = -1;
	l->player.ls_position = 0;
	l->player.max_level = 1;
	l->nb_col = 0;
	l->nb_en = 0;
	l->collision_map = malloc(sizeof(t_vector));
	init_tx(l);
	info("Game initiated");
}

void	init_ls(t_level *l)
{
	int			i;
	char		*tmp;
	t_vector	pos;

	i = -1;
	set_vector(&pos, 80, 100);
	while (++i <= 9)
	{
		tmp = add_str(add_str("./assets/09/n", ft_itoa(i), 2), ".xpm", 1);
		l->ls_09[i] = path_to_image(l, tmp);
		free(tmp);
		tmp = add_str("./assets/09/darker/n", ft_itoa(i), 2);
		tmp = add_str(tmp, ".xpm", 1);
		l->ls_09_dark[i] = path_to_image(l, tmp);
		free(tmp);
		if (i % 3 == 0)
			set_vector(&pos, 80, pos.y + 50);
		else
			pos.x += 80;
		l->ls_pos[i] = pos;
	}
}
