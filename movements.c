/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   movements.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/05 14:17:49 by lebojo			#+#	#+#			 */
/*   Updated: 2023/03/05 14:19:33 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "proto.h"

int	int_to_dir(int	key) //0 = gauche, 1 = haut, 2 = droite, 3 = bas, 4 = enter 0 = pas reconnu
{
	if (key == 2 || key == 124
		|| key == 65363 || key == 100)
		return (2);
	else if (key == 0 || key == 123
		|| key == 65361 || key == 97)
		return (0);
	else if (key == 13 || key == 126
		|| key == 65362 || key == 119)
		return (1);
	else if (key == 1 || key == 125
		|| key == 65364 || key == 115)
		return (3);
	else if (key == 36)
		return (4);
	else if (key == 53 || key == 65307)
		exit(info("Game closed"));
	return (0);
}

void	collision(t_level *l, t_vector pos, t_vector edge)
{
	int	i;
	int	col;

	i = -1;
	if (pos.x > edge.x - 54 || pos.x < 22)
		l->player.vel.x *= -1;
	if (pos.y < 54 || pos.y > edge.y - 22)
		l->player.vel.y *= -1;
	while (++i <= l->nb_col)
	{
		col = vector_collide(pos, l->collision_map[i], l->texture.width);
		if (col > 0)
		{
			if (col == 1)
				l->player.vel.y *= -1;
			if (col == 2)
				l->player.vel.x *= -1;
			break ;
		}
	}
}

void	collect_coins(t_level *l)
{
	int	i;

	i = -1;
	while (++i <= l->data.coins_max)
	{
		if (vector_collide(l->player.pos, l->coins_map[i], l->texture.width) != 0)
		{
			l->player.coins++;
			erase_coins(l, l->coins_map[i]);
			set_vector(&l->coins_map[i], -1, -1);
			print_score(l->player.coins, l->data.coins_max);
			break ;
		}
	}
}

void	exit_level(t_level *l)
{
	int col = vector_collide(l->player.pos, l->exit, l->texture.width);

	if (col != 0)
	{
		if (l->player.coins >= l->data.coins_max)
		{
			info(add_str("You win level ", l->name));
			mlx_destroy_window(l->params.mlx, l->params.mlx_win);
			free(l->map);
			free(l->map_matrix);
			free(l->coins_map);
			free(l->name);
			set_vector(&l->data.size, -1, 1);
			l->data.coins_max = 0;
			l->player.coins = 0;
			l->nb_col = 0;
			if (l->player.max_level == -1)
				exit(1);
			if (l->player.ls_position + 1 == l->player.max_level)
				l->player.max_level++;
			start_menu(l);
		}
		else
		{
			info("Ur 2 broke 2 die");
			hud_info(l, add_str(add_str("Score: ", score_to_str(l)), " - Ur 2 broke 2 die"));
			if (col == 1)
				l->player.vel.y *= -1;
			if (col == 2)
				l->player.vel.x *= -1;
		}
	}
}

void	player_process(t_level *l)
{
	int	max_speed;

	max_speed = 6;
	if (l->player.vel.x < max_speed && l->player.vel.x > -max_speed)
	{
		if (l->key[0] == 1)
			l->player.vel.x -= 2;
		if (l->key[2] == 1)
			l->player.vel.x += 2;
	}
	if (l->player.vel.y < max_speed && l->player.vel.y > -max_speed)
	{
		if (l->key[1] == 1)
			l->player.vel.y -= 2;
		if (l->key[3] == 1)
			l->player.vel.y += 2;
	}
}