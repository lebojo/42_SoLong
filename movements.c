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

#include "inc/proto.h"

int	int_to_dir(int key)
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
		col = vector_collide(pos, l->collision_map[i], l->tx.width);
		if (col > 0)
		{
			l->player.vel.x *= -1;
			l->player.vel.y *= -1;
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
		if (vector_collide(l->player.pos, l->map_c[i], l->tx.width) != 0)
		{
			l->player.coins++;
			erase_coins(l, l->map_c[i]);
			set_vector(&l->map_c[i], -1, -1);
			print_score(l->player.coins, l->data.coins_max);
			break ;
		}
	}
}

void	end_level(t_level *l)
{
	info(add_str("You win level ", l->name));
	info(add_str("With time: ", ft_itoa(l->time)));
	mlx_destroy_window(l->prm.mlx, l->prm.mlx_win);
	free(l->map);
	free(l->map_matrix);
	free(l->map_c);
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

void	exit_level(t_level *l)
{
	int		col;
	char	*tmp;

	col = vector_collide(l->player.pos, l->exit, l->tx.width);
	if (col != 0)
	{
		if (l->player.coins >= l->data.coins_max)
		{
			end_level(l);
		}
		else
		{
			info("Ur 2 broke 2 die");
			tmp = add_str("Score: ", score_to_str(l));
			tmp = add_str(tmp, " - Ur 2 broke 2 die");
			hud_info(l, tmp);
			free(tmp);
			if (col > 0)
			{
				l->player.vel.x *= -1;
				l->player.vel.y *= -1;
			}
		}
	}
}
