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
		if (cel == lvl->data.wall && pos.x >= 1 && pos.y >= 1 && pos.x < lvl->data.size.x - 1 && pos.y < lvl->data.size.y - 1)
			add_collision(lvl, pos, ++lvl->nb_col);
		if (cel == lvl->data.coins)
			add_coins(lvl, pos, ++lvl->data.coins_max);
		if (cel == lvl->data.exit)
			set_vector(&lvl->exit, pos.x * 32, (pos.y + 1) * 32);
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
	if (parse_validity(*lvl))
		exit(error("Incorrect map!"));
	lvl->params.mlx_win = mlx_new_window(lvl->params.mlx, lvl->data.size.x * lvl->texture.width, (lvl->data.size.y + 1) * lvl->texture.width, NAME);
	lvl->map_matrix = malloc(sizeof(char *) * lvl->data.size.y);
	lvl->map_matrix[0] = malloc(sizeof(char) * lvl->data.size.x);
	info("Building matrix...");
	build_matrix(lvl);
	if (!can_collect_coins(lvl))
		exit(error("Coin(s) can't be collected"));
	lvl->name = lvl_name_extractor(path);
	mlx_hook(lvl->params.mlx_win, 2, 0, key_press, lvl);
	mlx_hook(lvl->params.mlx_win, 3, 0, key_release, lvl);
	mlx_loop_hook(lvl->params.mlx, physics_process, lvl);
	mlx_loop(lvl->params.mlx);
}