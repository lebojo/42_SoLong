/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   build.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lebojo <lebojo@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/04/02 00:08:41 by lebojo			#+#	#+#			 */
/*   Updated: 2023/04/04 15:11:06 by lebojo		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "proto.h"

int	build_matrix(t_level *lvl)
{
	int			i;
	int			cel;
	t_vector	pos;
	
	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (lvl->map[i])
	{
		cel = lvl->map[i];
		if (cel == lvl->data.player)
		{
			lvl->player.pos.x = pos.x * lvl->texture.width;
			lvl->player.pos.y = pos.y * lvl->texture.width;
		}
		if (cel != '\n')
			pos.x += 1;
		else
		{
			pos.x = 0;
			pos.y += 1;
			lvl->map_matrix[pos.y] = malloc(sizeof(char) * (lvl->data.size.x + 1));
		}
		lvl->map_matrix[pos.y][pos.x] = cel;
		i++;
	}
	info("Matrix build!");
	return (0);
}

void	start_level(t_level *lvl, char *path)
{
	parse(path, lvl);
	lvl->params.mlx_win = mlx_new_window(lvl->params.mlx, lvl->data.size.x * lvl->texture.width, (lvl->data.size.y + 1) * lvl->texture.width, NAME);
	lvl->map_matrix = malloc(sizeof(char *) * lvl->data.size.y);
	lvl->map_matrix[0] = malloc(sizeof(char) * lvl->data.size.x);
	info("Building matrix...");
	build_matrix(lvl);
}