/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:22:18 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/21 18:33:07 by lebojo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "proto.h"

void	init_player_frames(t_level *l)
{
	t_vector	img;
	
	l->texture.player[0] = mlx_xpm_file_to_image(l->params.mlx, "./assets/player_frames/player1.xpm", &img.x, &img.y);
	l->texture.player[1] = mlx_xpm_file_to_image(l->params.mlx, "./assets/player_frames/player2.xpm", &img.x, &img.y);
	l->texture.player[2] = mlx_xpm_file_to_image(l->params.mlx, "./assets/player_frames/player3.xpm", &img.x, &img.y);
	l->texture.player[3] = mlx_xpm_file_to_image(l->params.mlx, "./assets/player_frames/player4.xpm", &img.x, &img.y);
	l->texture.pf.nb = 0;
	l->texture.pf.max = 3;
}

void	init_coins_frames(t_level *l)
{
	t_vector	img;
	
	l->texture.coins[0] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_1.xpm", &img.x, &img.y);
	l->texture.coins[1] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_2.xpm", &img.x, &img.y);
	l->texture.coins[2] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_3.xpm", &img.x, &img.y);
	l->texture.coins[3] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_4.xpm", &img.x, &img.y);
	l->texture.coins[4] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_5.xpm", &img.x, &img.y);
	l->texture.coins[5] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_6.xpm", &img.x, &img.y);
	l->texture.coins[6] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_7.xpm", &img.x, &img.y);
	l->texture.coins[7] = mlx_xpm_file_to_image(l->params.mlx, "./assets/coins_frames/coins_8.xpm", &img.x, &img.y);
	l->texture.cf.nb = 0;
	l->texture.cf.max = 7;
}

void	init_level(t_level *level)
{
	int			img_width;
	int			img_height;

	level->state = 0;
	level->data.coins = 'C';
	level->data.empty = '0';
	level->data.wall = '1';
	level->data.exit = 'E';
	level->data.player = 'P';
	set_vector(&level->data.size, -1, 1);
	level->data.coins_max = 0;
	level->player.coins = 0;
	set_vector(&level->player.vel, -1, 0);
	level->player.pos.x = -1;
	level->player.ls_position = 0;
	level->player.max_level = 1;
	level->nb_col = 0;
	level->collision_map = malloc(sizeof(t_vector));
	init_player_frames(level);
	init_coins_frames(level);
	level->texture.empty = mlx_xpm_file_to_image(level->params.mlx, "./assets/floor.xpm", &img_width, &img_height);
	level->texture.wall = mlx_xpm_file_to_image(level->params.mlx, "./assets/wall.xpm", &img_width, &img_height);
	level->texture.exit = mlx_xpm_file_to_image(level->params.mlx, "./assets/enemy.xpm", &img_width, &img_height);
	level->texture.blck = mlx_xpm_file_to_image(level->params.mlx, "./assets/blck.xpm", &img_width, &img_height);
	level->texture.width = 32;
	info("Game initiated");
}

void	init_ls(t_level *l)
{
	t_vector	img;

	l->ls_pos[0] = vector(80, 100);
	l->ls_pos[1] = vector(160, 100);
	l->ls_pos[2] = vector(240, 100);
	l->ls_pos[3] = vector(80, 150);
	l->ls_pos[4] = vector(160, 150);
	l->ls_pos[5] = vector(240, 150);
	l->ls_pos[6] = vector(80, 200);
	l->ls_pos[7] = vector(160, 200);
	l->ls_pos[8] = vector(240, 200);
	l->ls_pos[9] = vector(160, 400);
	l->ls_09[0] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n0.xpm", &img.x, &img.y);
	l->ls_09[1] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n1.xpm", &img.x, &img.y);
	l->ls_09[2] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n2.xpm", &img.x, &img.y);
	l->ls_09[3] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n3.xpm", &img.x, &img.y);
	l->ls_09[4] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n4.xpm", &img.x, &img.y);
	l->ls_09[5] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n5.xpm", &img.x, &img.y);
	l->ls_09[6] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n6.xpm", &img.x, &img.y);
	l->ls_09[7] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n7.xpm", &img.x, &img.y);
	l->ls_09[8] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n8.xpm", &img.x, &img.y);
	l->ls_09[9] = mlx_xpm_file_to_image(l->params.mlx, "./assets/09/n9.xpm", &img.x, &img.y);
}