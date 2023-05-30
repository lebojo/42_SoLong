/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebojo <lebojo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 05:44:23 by lebojo            #+#    #+#             */
/*   Updated: 2023/05/30 03:56:44 by lebojo           ###   ########.fr       */
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
	res = add_str(scr, "/");
	res = add_str(res, mx);
	return (res);
}

void	hud_info(t_level *l, char *s)
{
	int		margin;
	char	*tmp;

	draw_hud(l);
	tmp = add_str("level: ", l->name);
	mlx_string_put(l->prm.mlx, l->prm.mlx_win, 10, 21, 0xFFFFFF, tmp);
	margin = (ft_strlen(l->name) + 7) * 10;
	tmp = add_str(add_str(s, " - Time: "), ft_itoa(l->time));
	mlx_string_put(l->prm.mlx, l->prm.mlx_win, margin, 21, 0xFFFFFF, tmp);
}
