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

int draw_cell(t_level *lvl, char c, t_params prm, t_vector pos)
{
	if (c == '\n')
		return (0);
	if (c == lvl->data.player)
	{
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.player, pos.x, pos.y);
		lvl->player.pos = pos;
	}
	if (c == lvl->data.collect)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.collect, pos.x, pos.y);
	else if (c == lvl->data.empty)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.empty, pos.x, pos.y);
	else if (c == lvl->data.exit)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.exit, pos.x, pos.y);
	else if (c == lvl->data.wall)
		mlx_put_image_to_window(prm.mlx, prm.mlx_win, lvl->texture.wall, pos.x, pos.y);
	lvl->map_matrix[(pos.y/32) - 1][pos.x/32] = c;
	return (1);
}

void build_level(t_level *lvl)
{
	int i;
	int cel;
	t_vector pos;
	
	i = 0;
	pos.x = 0;
	pos.y = lvl->texture.width;
	lvl->map_matrix[0] = malloc(sizeof(char) * lvl->data.size.x);
	while (lvl->map[i])
	{
		cel = draw_cell(lvl, lvl->map[i], lvl->params, pos);
		if (cel != 0)
			pos.x += lvl->texture.width;
		else
		{
			pos.x = 0;
			pos.y += lvl->texture.width;
			lvl->map_matrix[(pos.y/32) - 1] = malloc(sizeof(char) * (lvl->data.size.x + 1));
		}
		i++;
	}
	info("Level build!");
}