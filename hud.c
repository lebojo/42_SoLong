/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchapell <jchapell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:44:23 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 22:51:57 by jchapell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/proto.h"

char	*score_to_str(t_level *l)
{
	char	*res;
	char	*scr;
	char	*mx;

	scr = ft_itoa(l->player.coins);
	mx = ft_itoa(l->data.coins_max);
	res = add_str(scr, "/", 1);
	res = add_str(res, mx, 3);
	return (res);
}

void	hud_info(t_level *l, char *s)
{
	char	*tmp;

	draw_hud(l);
	tmp = add_str("level: ", l->name, 0);
	tmp = add_str(tmp, " | Coins: ", 1);
	tmp = add_str(tmp, score_to_str(l), 3);
	tmp = add_str(tmp, " - Move: ", 1);
	tmp = add_str(tmp, ft_itoa(l->player.move), 3);
	tmp = add_str(add_str(tmp, " - Time: ", 1), ft_itoa(l->time), 3);
	tmp = add_str(tmp, s, 1);
	mlx_string_put(l->prm.mlx, l->prm.mlx_win, 10, 21, 0xFFFFFF, tmp);
	free(tmp);
}
