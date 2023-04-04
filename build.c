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

int draw_cell(t_level lvl, char c, t_params prm, t_vector pos)
{
	int	img_width;
	int	img_height;

	if (c == '\n')
		return (0);
	if (c == lvl.data.collect)
		prm.img = mlx_xpm_file_to_image(prm.mlx, lvl.texture.collect, &img_width, &img_height);
	else if (c == lvl.data.empty)
		prm.img = mlx_xpm_file_to_image(prm.mlx, lvl.texture.empty, &img_width, &img_height);
	else if (c == lvl.data.exit)
		prm.img = mlx_xpm_file_to_image(prm.mlx, lvl.texture.exit, &img_width, &img_height);
	else if (c == lvl.data.player)
		prm.img = mlx_xpm_file_to_image(prm.mlx, lvl.texture.player, &img_width, &img_height);
	else if (c == lvl.data.wall)
		prm.img = mlx_xpm_file_to_image(prm.mlx, lvl.texture.wall, &img_width, &img_height);
	mlx_put_image_to_window(prm.mlx, prm.mlx_win, prm.img, pos.x, pos.y);
	return (1);
}

void build_level(t_level lvl, t_params prm)
{
	int i;
	int cel;
	t_vector pos;
	
	i = 0;
	while (lvl.map[i])
	{
		cel = draw_cell(lvl, lvl.map[i], prm, pos);
		if (cel != 0)
			pos.x += lvl.texture.width;
		else
		{
			pos.x = 0;
			pos.y += lvl.texture.width;
		}
		i++;
	}
	info("Level build!");
}