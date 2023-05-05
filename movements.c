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

char	int_to_dir(int	key)
{
	if (key == 2 || key == 124
		|| key == 65363 || key == 100)
		return ('R');
	else if (key == 0 || key == 123
		|| key == 65361 || key == 97)
		return ('L');
	else if (key == 13 || key == 126
		|| key == 65362 || key == 119)
		return ('U');
	else if (key == 1 || key == 125
		|| key == 65364 || key == 115)
		return ('D');
	else if (key == 53 || key == 65307)
		exit(0);
	return (0);
}

char	move_id(t_vector pos, char **map_matrix, char dir) //0 = move; 1 = move + coins; 2 = No move
{
	t_vector	m_pos;
	
	m_pos = pixel_to_matrix(pos);
	if (dir == 'R')
			return (map_matrix[m_pos.y][m_pos.x + 1]);
	if (dir == 'L')
		return (map_matrix[m_pos.y][m_pos.x - 1]);
	if (dir == 'U')
		return (map_matrix[m_pos.y - 1][m_pos.x]);
	if (dir == 'D')
		return (map_matrix[m_pos.y + 1][m_pos.x]);
	return (0);
}

void	move_draw(t_level *lvl, char dir, char id)
{
	t_vector	m_pos;

	if (id == lvl->data.exit)
	{
		if (lvl->player.coins >= lvl->data.coins_max)
			exit(info("You win!"));
		else
			info("You should'nt die broke");
		return ;
	}
	if (id != lvl->data.wall)
		mlx_put_image_to_window(lvl->params.mlx, lvl->params.mlx_win, lvl->texture.empty, lvl->player.pos.x, lvl->player.pos.y);
	if (dir == 'R' && id != lvl->data.wall)
			lvl->player.pos.x += lvl->player.vel;
	else if (dir == 'L' && id != lvl->data.wall)
		lvl->player.pos.x -= lvl->player.vel;
	else if (dir == 'U' && id != lvl->data.wall)
		lvl->player.pos.y -= lvl->player.vel;
	else if (dir == 'D' && id != lvl->data.wall)
		lvl->player.pos.y += lvl->player.vel;
	m_pos = pixel_to_matrix(lvl->player.pos);
	if (id == lvl->data.collect)
	{
		lvl->map_matrix[m_pos.y][m_pos.x] = lvl->data.empty;
		lvl->player.coins++;
		print_score(lvl->player.coins, lvl->data.coins_max);
	}
	draw_player(lvl);
}