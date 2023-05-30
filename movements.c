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
	char	*tmp;

	tmp = add_str("You win level ", l->name, 0);
	tmp = add_str(tmp, ", With time: ", 1);
	tmp = add_str(tmp, ft_itoa(l->time), 3);
	info(tmp);
	free(tmp);
	mlx_destroy_window(l->prm.mlx, l->prm.mlx_win);
	if (l->player.max_level == -1)
		clean_exit(l);
	free_level(l);
	set_vector(&l->data.size, -1, 1);
	l->data.coins_max = 0;
	l->player.coins = 0;
	l->nb_col = 0;
	if (l->player.ls_position + 1 == l->player.max_level)
		l->player.max_level++;
	start_menu(l);
}

void	exit_level(t_level *l)
{
	int		col;

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
			if (col > 0)
			{
				l->player.vel.x *= -1;
				l->player.vel.y *= -1;
			}
		}
	}
}
