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

t_vector	pixel_to_matrix(t_vector pos)
{
	pos.x /= 32;
	pos.y /= 32;
	pos.y -= 1;
	return (pos); 
}

int	int_to_dir(int	key) //1 = gauche, 2 = haut, 3 = droite, 4 = bas, 0 = pas reconnu
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
	else if (key == 53 || key == 65307)
		exit(info("Game closed"));
	return (0);
}

t_vector	collision(t_level *l, t_vector pos, t_vector edge)
{
	t_vector	res;
	int			i;

	i = -1;
	set_vector(&res, 0, 0);
	if (pos.x > edge.x - 54 || pos.x < 22)
		res.x = 1;
	if (pos.y < 54 || pos.y > edge.y - 22)
		res.y = 1;
	while (++i <= l->nb_col)
	{
		if (vector_collide(pos, l->collision_map[i], l->texture.width))
			set_vector(&res, 1, 1);
	}
	return (res);
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