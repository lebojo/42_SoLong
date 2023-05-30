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

#include "inc/proto.h"

void	set_matrix_cel(t_level *l, int i, t_vector *pos, int cel)
{
	int	w;

	w = l->tx.width;
	if (cel == l->data.player)
		set_vector(&l->player.pos, pos->x * w, (pos->y + 1) * w);
	if (cel == l->data.wall && pos->x >= 1 && pos->y >= 1
		&& pos->x < l->data.size.x - 1 && pos->y < l->data.size.y - 1)
		add_collision(l, *pos, ++l->nb_col);
	if (cel == l->data.coins)
		add_coins(l, *pos, ++l->data.coins_max);
	if (cel == l->data.exit)
		set_vector(&l->exit, pos->x * 32, (pos->y + 1) * 32);
	if (cel != '\n')
		pos->x += 1;
	else
	{
		pos->x = 0;
		pos->y += 1;
		l->map_matrix[pos->y] = malloc(sizeof(char) * (l->data.size.x + 1));
		i++;
		return ;
	}
	l->map_matrix[pos->y][pos->x] = cel;
}

int	build_matrix(t_level *lvl)
{
	int			i;
	t_vector	pos;

	i = -1;
	set_vector(&pos, 0, 0);
	while (lvl->map[++i])
		set_matrix_cel(lvl, i, &pos, lvl->map[i]);
	info("Matrix build!");
	return (0);
}

void	start_level(t_level *l, char *path)
{
	int			w;
	t_vector	w_s;

	w = l->tx.width;
	parse(path, l);
	if (parse_validity(*l))
		exit(error("Incorrect map!"));
	set_vector(&w_s, l->data.size.x * w, (l->data.size.y + 1) * w);
	create_new_window(l, w_s);
	l->map_matrix = malloc(sizeof(char *) * l->data.size.y);
	l->map_matrix[0] = malloc(sizeof(char) * l->data.size.x);
	info("Building matrix...");
	build_matrix(l);
	if (can_collect_coins(l) == 0)
		exit(error("Coin(s) can't be collected"));
	l->name = lvl_name_extractor(path);
	draw_level(l);
	mlx_hook(l->prm.mlx_win, 2, 0, key_press, l);
	mlx_hook(l->prm.mlx_win, 3, 0, key_release, l);
	mlx_loop_hook(l->prm.mlx, physics_process, l);
	mlx_loop(l->prm.mlx);
}
