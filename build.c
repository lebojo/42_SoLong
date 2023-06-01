/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 03:52:24 by jchapell          #+#    #+#             */
/*   Updated: 2023/06/01 05:06:17 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

void	set_matrix_cel(t_level *l, t_vector *pos, int cel)
{
	int	w;

	w = l->tx.width;
	if (cel == l->data.player)
		set_vector(&l->player.pos, pos->x * w, (pos->y + 1) * w);
	if (cel == l->data.wall && pos->x >= 1 && pos->y >= 1
		&& pos->x < l->data.size.x - 1 && pos->y < l->data.size.y - 1)
		add_collision(l, *pos, ++l->nb_col);
	if (cel == l->data.enemy)
		add_enemy(l, *pos, ++l->nb_en);
	if (cel == l->data.coins)
		add_coins(l, *pos, ++l->data.coins_max);
	if (cel == l->data.exit)
	{
		set_vector(&l->exit, pos->x * 32, (pos->y + 1) * 32);
		set_vector(&l->exit_mx, pos->x + 1, (pos->y));
	}
	if (cel == '\n')
	{
		set_vector(pos, 0, pos->y + 1);
		l->map_matrix[pos->y] = malloc(sizeof(char) * (l->data.size.x + 1));
		return ;
	}
	pos->x += 1;
	l->map_matrix[pos->y][pos->x] = cel;
}

int	build_matrix(t_level *lvl)
{
	int			i;
	t_vector	pos;

	i = -1;
	set_vector(&pos, 0, 0);
	while (lvl->map[++i])
		set_matrix_cel(lvl, &pos, lvl->map[i]);
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
	l->data.coins_max = 0;
	build_matrix(l);
	level_validity(l);
	l->name = lvl_name_extractor(path);
	draw_level(l);
	l->player.move = 0;
	mlx_hook(l->prm.mlx_win, 2, 0, key_press, l);
	mlx_hook(l->prm.mlx_win, 17, 0, clean_exit, l);
	mlx_hook(l->prm.mlx_win, 3, 0, key_release, l);
	mlx_loop_hook(l->prm.mlx, physics_process, l);
	mlx_loop(l->prm.mlx);
}
