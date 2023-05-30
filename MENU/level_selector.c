/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_selector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:35:06 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 22:53:48 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/proto.h"

void	draw_menu_level(t_level *l, t_vector *p)
{
	int	i;

	i = -1;
	while (++i < 9)
	{
		if (i < l->player.max_level)
			draw_image(l, l->ls_09[i + 1], p[i]);
		else
			draw_image(l, l->ls_09_dark[i + 1], p[i]);
	}
}

void	pp_calc(t_level *l, int	*pp, int key)
{
	if (*pp == 0 && l->player.max_level >= 8 && key == 0)
		*pp = 8;
	else if (*pp != 0 && key == 0)
		*pp -= 1;
	if ((*pp == 0 || *pp == 1 || *pp == 2)
		&& *pp + 6 <= l->player.max_level && key == 1)
		*pp += 6;
	else if (!(*pp == 0 || *pp == 1 || *pp == 2) && key == 1)
		*pp -= 3;
	if (*pp == 8 && key == 2)
		*pp = 0;
	else if (*pp + 1 < l->player.max_level && key == 2)
		*pp += 1;
	if ((*pp == 6 || *pp == 7 || *pp == 8)
		&& *pp - 6 <= l->player.max_level && key == 3)
		*pp -= 6;
	else if (*pp + 3 <= l->player.max_level && key == 3)
		*pp += 3;
	reset_keys(l);
}

void	player_position(t_level *l)
{
	int	pp;

	pp = l->player.ls_position;
	if (l->key[0] == 1)
		pp_calc(l, &pp, 0);
	if (l->key[1] == 1)
		pp_calc(l, &pp, 1);
	if (l->key[2] == 1)
		pp_calc(l, &pp, 2);
	if (l->key[3] == 1)
		pp_calc(l, &pp, 3);
	l->player.pos = l->ls_pos[pp];
	l->player.pos.x -= l->tx.width;
	l->player.ls_position = pp;
}

void	launch_level(t_level *l)
{
	char	*path;
	char	*tmp;

	if (l->key[4] == 1)
	{
		path = add_str("maps/", ft_itoa(l->player.ls_position + 1), 2);
		mlx_destroy_window(l->prm.mlx, l->prm.mlx_win);
		reset_keys(l);
		set_vector(&l->player.vel, 0, 0);
		tmp = add_str("Starting level ", ft_itoa(l->player.ls_position), 2);
		info(tmp);
		free(tmp);
		path = add_str(path, ".ber", 1);
		start_level(l, path);
	}
}

void	start_menu(t_level *l)
{
	l->player.pos.y = 180;
	l->player.pos.x = 110;
	create_new_window(l, vector(350, 350));
	draw_bcgk(l, vector(0, 0), vector(350, 350));
	init_ls(l);
	mlx_hook(l->prm.mlx_win, 2, 0, key_press, l);
	mlx_hook(l->prm.mlx_win, 3, 0, key_release, l);
	mlx_hook(l->prm.mlx_win, 17, 0, clean_exit, l);
	mlx_loop_hook(l->prm.mlx, level_selector_process, l);
	mlx_loop(l->prm.mlx);
}
