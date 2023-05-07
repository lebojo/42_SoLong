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
			set_vector(&lvl->player.pos, pos.x * lvl->texture.width, (pos.y + 1) * lvl->texture.width);
		if (cel == lvl->data.wall && pos.x > 1 && pos.y > 1 && pos.x < lvl->data.size.x - 1 && pos.y < lvl->data.size.y - 1)
		{
			add_collision(lvl, pos, ++lvl->nb_col);
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

void	add_collision(t_level *l, t_vector pos, int nb_col)
{
	t_vector	*new_map;
	int			i;

	i = -1;
	set_vector(&pos, pos.x * l->texture.width, (pos.y + 1) *l->texture.width);
	new_map = malloc(sizeof(t_vector) * nb_col);
	if (nb_col > 1)
	{
		while (++i < nb_col)
			new_map[i] = l->collision_map[i];
	free(l->collision_map);
	}
	new_map[0] = pos;
	l->collision_map = new_map;
}

void	start_level(t_level *lvl, char *path)
{
	parse(path, lvl);
	//ft_putstr_fd(lvl->map, 0);
	lvl->params.mlx_win = mlx_new_window(lvl->params.mlx, lvl->data.size.x * lvl->texture.width, (lvl->data.size.y + 1) * lvl->texture.width, NAME);
	lvl->map_matrix = malloc(sizeof(char *) * lvl->data.size.y);
	lvl->map_matrix[0] = malloc(sizeof(char) * lvl->data.size.x);
	info("Building matrix...");
	build_matrix(lvl);
}