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
		return (3);
	else if (key == 0 || key == 123
		|| key == 65361 || key == 97)
		return (1);
	else if (key == 13 || key == 126
		|| key == 65362 || key == 119)
		return (2);
	else if (key == 1 || key == 125
		|| key == 65364 || key == 115)
		return (4);
	else if (key == 53 || key == 65307)
		exit(info("Game closed"));
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